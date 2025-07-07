class Box {
    min_x = 0; 
    max_x = 0
    min_y = 0;
    max_y = 0;
    width = 0;
    height = 0;


  
    constructor(x, y, width, height) {
        this.min_y = y;
        this.max_y = y + height; 
        this.min_x = x; 
        this.max_x = x + width;
        this.width = width;
        this.height = height;
    }

    is_within(x, y) {
        return (this.min_x < x && x < this.max_x 
             && this.min_y < y && y < this.max_y);
    }

    overlap(other_box) {
        return this.max_x >= other_box.get_x() && other_box.get_max_x() >= this.min_x
             & this.max_y >= other_box.get_y() && other_box.get_max_y() >= this.min_y;
    }

    log() {
        console.log(`boundaries - min y: ${this.min_y}, max y: ${this.max_y}, min x: ${this.min_x}, max x: ${this.max_x}`);
    }

    set_pos(x, y) {
        this.set_x(x);
        this.set_y(y);
    }

    set_x(x) {
        this.min_x = x;
        this.max_x = x + this.width;
    }

    set_y(y) {
        this.min_y = y;
        this.max_y = y + this.height;
    }

    set_width(width) {
        this.width = width;
        this.max_x = this.min_x + this.width;
    }

    set_height(height) {
        this.height = height;
        this.max_y = this.min_y + this.height;
    }

    get_center() {
        return {x: this.min_x + (this.width / 2),
                y: this.min_y + (this.height / 2)};
    }

    draw(ctx, abs_x, abs_y) {
        ctx.rect(this.min_x + abs_x, this.min_y + abs_y, this.width, this.height);
        ctx.stroke();
    }

    get_x() { return this.min_x; }
    get_y() { return this.min_y; }
    get_max_x() { return this.max_x; }
    get_max_y() { return this.max_y; }
    get_height() { return this.height; }
    get_width() { return this.width; }
}
  