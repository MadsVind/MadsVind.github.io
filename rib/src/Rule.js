export class Rule {
    premise_text = STANDARD_TEXT; 
    premise_list = []
    conclussion = STANDARD_TEXT; 
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
  
    get_premise() {
      return (this.is_premise_text()) ? this.premise_text : this.premise_list;
    }
  
    is_premise_text() {return this.premise_list.length == 0;}
    get_x() { return this.x; }
    get_y() { return this.y; }
    get_height() { return this.height; }
    get_width() { return this.width; }
}
  