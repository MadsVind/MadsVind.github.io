class Text {
    text = null;
    box = null;
    cursor_idx = null;
    active = false;
    rule = null;

    constructor(x, y, width, height, text, rule) {
        this.text = text;
        this.rule = rule;
        this.box = new Box(x, y, width, height)
    }

    draw(ctx, debug=false, abs_x, abs_y) {
        const box = this.box;
        const x = box.get_x() + abs_x;
        const y = box.get_y() + abs_y;
        ctx.fillText(this.text, 
                     x, 
                     y + box.get_height());
        if (this.active) {
            const cursor_x = ctx.measureText(this.text.substring(0, this.cursor_idx)).width
            ctx.moveTo(x + cursor_x, y);
            ctx.lineTo(x + cursor_x, y + this.box.get_height());
            ctx.stroke();
        }
        if (debug == true) box.draw(ctx, abs_x, abs_y);
    }

    backspace() {
        this.text = this.text.substring(0, this.cursor_idx - 1) + this.text.substring(this.cursor_idx);
        this.cursor_left();
    }

    delete() {
        this.text = this.text.substring(0, this.cursor_idx) + this.text.substring(this.cursor_idx + 1); 
    }

    // should update cursor idx after command usage
    add_char(char) {
        this.text = this.text.substring(0, this.cursor_idx) + char + this.text.substring(this.cursor_idx);
        if (this.is_word_at_cursor_command(this.cursor_idx)) this.replace_command(this.cursor_idx); 
        this.cursor_right();
    }

    // think cursor should be managed by the event
    set_text(str) {
        this.text = str;
        if (this.is_word_at_cursor_command(this.cursor_idx)) this.replace_command(this.cursor_idx); 
        this.cursor_idx = this.get_text_length();
    }

    get_text() {
        return this.text;
    }

    replace_command() {
        const start_pos = this.find_word_start();
        const end_pos = this.find_word_end();
        const current_word = this.text.substring(start_pos, end_pos);

        const utf_code = latex_utf_json[current_word]; 
        if (utf_code != undefined) {
            this.text = this.text.substring(0, start_pos) + String.fromCharCode(utf_code) + this.text.substring(end_pos)
            this.cursor_idx -= (current_word.length - 1);
        }
    }

    is_word_at_cursor_command() {
        for (let i = this.cursor_idx; i >= 0; --i) {
            const char_code = this.text.charCodeAt(i) ;

            if      (char_code === 92) return true;  // 92 is "\"
            else if (char_code === 32) return false; // 32 is " "
        }
        return false;
    }

    find_word_start() {
        for (let i = this.cursor_idx; i >= 0; --i) {
            if (this.text.charCodeAt(i) === 32) return i + 1;
        }
        return 0;
    }

    find_word_end() {
        for (let i = this.cursor_idx; i < this.text.length; ++i) {
            if (this.text.charCodeAt(i) === 32) return i;
        }
        return this.text.length;
    }

    get_text_length() {
        return this.text.length;
    }

    get_box() { return this.box; }

    update_size(ctx) {
        this.box.set_width(Math.max(ctx.measureText(this.text).width,
                        LEAST_TEXT_WIDTH));
    }

    activate(x, ctx) {
        this.active = true;
        this.cursor_idx_from_x(x, ctx);
    }

    cursor_idx_from_x(x, ctx) {
        const abs_x = this.rule.get_absolute_x() + this.box.get_x();
        const rel_x = x - abs_x; 
        let text_x = 0;
        let i = 0;
          
        for (; i < this.text.length; ++i) {
            text_x += ctx.measureText(this.text[i]).width; 
            if (rel_x < text_x) break;
        }
        this.cursor_idx = i;
    }

    deactivate() {
        this.active = false;
        this.cursor_idx = -1;
    }

    cursor_left() {
        if (this.cursor_idx > 0) this.cursor_idx--;
    }

    cursor_right() {
        if (this.cursor_idx < this.text.length) this.cursor_idx++;
    }
}