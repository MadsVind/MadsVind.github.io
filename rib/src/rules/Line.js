class Line {
    x = 0;
    y = 0;
    width = 0;

    constructor(x, y, width) {
        this.x = x;
        this.y = y;
        this.width = width;
    }

    draw(ctx, abs_x, abs_y) {
        const x = this.x + abs_x;
        const y = this.y + abs_y;
        ctx.beginPath();
        ctx.moveTo(x, y);
        ctx.lineTo(x + this.width, y);
        ctx.stroke();
    }

    set_width(width) {
        this.width = width;
    }

    set_pos(x, y) {
        this.x = x;
        this.y = y;
    }

    set_y(y) {
        this.y = y;
    }
}