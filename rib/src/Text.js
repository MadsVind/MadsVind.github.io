class Text {
    text = null;
    box = null;

    constructor(x, y, width, height, text) {
        this.text = text;
        this.box = new Box(x, y, width, height)
    }

    draw(ctx, debug=false, abs_x, abs_y) {
        const box = this.box;
        const x = box.get_x() + abs_x;
        const y = box.get_y() + abs_y;
        ctx.fillText(this.text, 
                     x, 
                     y + box.get_height());
        //if (debug == true) box.draw(ctx, abs_x, abs_y);
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