class Rule {
    box = null;
    conclussion_text = null; 
    premise_text = null; 
    premise_list = []
    line = null;
    line_space = 5;
    
  
    constructor(x, y, ctx) { // Use of FONT_SIZE should be made dynamic!
        const width  = ctx.measureText(STANDARD_TEXT).width;
        const height = FONT_SIZE;
        x = x - width / 2;
        y = y - height;
        this.premise_text = new Text(x, y, width, height, STANDARD_TEXT);
        this.line = new Line(x, y + height + this.line_space, width);
        this.conclussion_text = new Text(x, y + height, width, height, STANDARD_TEXT);
        this.box = new Box(x, y, width, height * 2);
    }

    draw(ctx, debug=false) {
        const box = this.box;
        this.line.draw(ctx);
        if (this.is_premise_text())  {
            this.premise_text.draw(ctx, debug);
            this.conclussion_text.draw(ctx, debug);
        }
        else return "to be done";
                    
        if (debug == true) {
            box.draw(ctx);
        }
    }

    set_pos(x, y) {
        const premise_box = this.premise_text.get_box();
        const conclussion_box = this.conclussion_text.get_box();

        premise_box.set_pos(x, y);
        this.line.set_pos(x, y + premise_box.height + this.line_space) 
        conclussion_box.set_pos(x, y + premise_box.height);
        this.box.set_pos(x, y);
    }
  
    get_premise() {
      return (this.is_premise_text()) ? this.premise_text : this.premise_list;
    }
    get_conclussion() {
        return this.conclussion_text;
    }

    update_size(ctx) {
        this.conclussion_text.update_size(ctx);
        this.premise_text.update_size(ctx);
        const width = Math.max(this.conclussion_text.get_box().get_width(),
                               this.premise_text.get_box().get_width());
        this.line.set_width(width);
    }
  
    is_premise_text() {return this.premise_list.length == 0;}
    get_box() { return this.box; }
}

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
        this.box.set_width(ctx.measureText(this.text).width);
    }
}

class Line {
    x = 0;
    y = 0;
    width = 0;

    constructor(x, y, width) {
        this.x = x;
        this.y = y;
        this.width = width;
    }

    draw(ctx) {
        ctx.beginPath();
        ctx.moveTo(this.x, this.y);
        ctx.lineTo(this.x + this.width, this.y);
        ctx.stroke();
    }

    set_width(width) {
        this.width = width;
    }

    set_pos(x, y) {
        this.x = x;
        this.y = y;
    }
}
  
class Box {
    x = 0; 
    y = 0;
    width = 0;
    height = 0;
  
    constructor(x, y, width, height) {
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
    }

    is_within(x, y) {
        const top = this.y;
        const bot = this.y + this.height; 
        const left = this.x; 
        const right = this.x + this.width;
        return (left < x && x < right && top < y && y < bot);
    }

    log() {
        console.log(`boundaries - Bot: ${this.y + this.height}, Top: ${this.y}, Left: ${this.x}, Right: ${this.x + this.width}`);
    }

    set_pos(x, y) {
        this.x = x;
        this.y = y;
    }

    set_width(width) {
        this.width = width;
    }

    set_height(height) {
        this.height = height;
    }

    get_center() {
        return {x: this.x + (width / 2),
                y: this.y + (height / 2)};
    }

    draw(ctx) {
        ctx.rect(this.x, this.y, this.width, this.height);
        ctx.stroke();
    }

    get_x() { return this.x; }
    get_y() { return this.y; }
    get_height() { return this.height; }
    get_width() { return this.width; }
}
  