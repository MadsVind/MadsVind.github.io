class Text {
    text = null;
    box = null;

    constructor(x, y, width, height, text) {
        this.text = text;
        this.box = new Box(x, y, width, height)
    }

    draw(ctx, debug=false) {
        const box = this.box;
        ctx.fillText(this.text, 
                     box.get_x(), 
                     box.get_y() + box.get_height());
        if (debug == true) box.draw(ctx);
    }

    backspace() { // w need to have a cursor instead and this should then be dynamic
        this.text = this.text.slice(0, -1);
    }

    add_char(char) {
        this.text = this.text + char;
    }

    get_box() { return this.box; }

    update_size(ctx) {
        this.box.set_width(Math.max(ctx.measureText(this.text).width,
                        LEAST_TEXT_WIDTH));
    }
}