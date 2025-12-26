
class WordChange extends Change {
    before_text  = null;
    after_text   = null;
    text_obj     = null;

    constructor(text_obj, before_text, after_text) {
        super();
        this.before_text = before_text;
        this.after_text  = after_text; 
        this.text_obj    = text_obj;
    }

    undo() {
        this.text_obj.set_text(this.before_text); 
    }
 
    do() {
        this.text_obj.set_text(this.after_text);       
    }
}