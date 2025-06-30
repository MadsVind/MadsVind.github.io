export class Canvas {
    constructor(id) {
      this.id = id;
      this.rule_list = [];
      this.ctx = document.getElementById(this.id).getContext("2d");
    }
  
    update() {
      for (let rule of this.rule_list) {
        this.#write_rule(rule);
      }
    }
  
    #write_rule(rule) {
      const x = rule.get_x();
      const y = rule.get_y();
      const height = rule.get_height();
      const width = rule.get_width();
      if (rule.is_premise_text())  {
        this.ctx.fillText(rule.get_premise(), x - (width / 2), y + (height / 2));
      }
      else
        return "tbd";
  
    }
  
    add(x, y) {
      const width = this.ctx.measureText(STANDARD_TEXT).width
      this.rule_list.push(new Rule(x, y, width, FONT_SIZE));
      this.update();
    }
}
