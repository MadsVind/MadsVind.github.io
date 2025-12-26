class EventHandler {
    event_queue    = [];
    change_handler = null;
    rule_handler   = null;

    constructor(change_handler, rule_handler) {
        this.change_handler = change_handler;
        this.rule_handler   = rule_handler;
    }

    add(event) {
        if (event.is_ended()) return;
        
        this.event_queue.push(event);
        this.undone_event_stack = [];
    }

    end() {
        const current_event = this.event_queue.shift();

        if (current_event == null) 
            return;

        if (!current_event.end()) 
            return;

    }

    move(x, y) {
        const current_event = this.event_queue[0];

        if (current_event == null || !current_event.is_move_event()) return false;
            
        current_event.move(x, y);

        return true;
    }

    key_input(key) {
        const current_event = this.event_queue[0];
        
        if (current_event == null || !current_event.is_write_event()) return false;

        current_event.write(key);

        return true;
    }
}