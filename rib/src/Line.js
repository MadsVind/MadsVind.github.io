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