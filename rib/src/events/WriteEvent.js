
class WriteEvent extends Event {
    rule_handler   = null;
    change_handler = null;

    rule = null;
    text = null;
    ctx  = null;

    is_last_space     = false;
    is_last_delete    = false;
    is_last_backspace = false;

    constructor(x, text, rule, ctx, rule_handler, change_handler) {
        super();
        this.rule_handler   = rule_handler;
        this.change_handler = change_handler;

        this.rule = rule;
        this.text = text;

        this.ctx = ctx;
        
        this.before_text_str = this.text.get_text();
        this.text.activate(x, this.ctx);
        this.rule_handler.set_active_text(text); 
    }

    write(key) {
        switch (key) {
            case "Backspace": 
                if (!this.is_last_backspace) 
                    this.add_change();
                this.is_last_backspace = true;

                this.text.backspace();
                break;
            case "Delete":
                if (!this.is_last_delete) 
                    this.add_change();
                this.is_last_delete = true;
                this.text.delete()
                break;
            case "ArrowLeft":
                this.text.cursor_left();
                break;
            case "ArrowRight":  
                this.text.cursor_right();
                break;
            case " ":
                if (!this.is_last_space) 
                    this.add_change();
                this.is_last_space = true;
                this.text.add_char(key);
                break;
            default:
                if (key.length > 1) 
                    return;
                if (this.is_last_space) 
                    this.add_change();

                this.is_last_space     = false;
                this.is_last_delete    = false;
                this.is_last_backspace = false;

                this.text.add_char(key);
        }
    }

    add_change() {
        const current_text = this.text.get_text();
        if (this.before_text_str == current_text)
            return;

        this.change_handler.add(new WordChange(this.text, this.before_text_str, current_text));
        this.before_text_str = current_text;
    }
 
    end() {
        super.end();
        if (this.text == null) return false;
        this.add_change();
        this.text.deactivate();
        return true;
    }

    is_write_event() {
        return true;
    }

    get_text() {
        return this.text;
    }
}

