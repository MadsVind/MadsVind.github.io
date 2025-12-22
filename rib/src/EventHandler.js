class EventHandler{
    BACKLOG_SIZE = 20;
    done_event_list = [];
    undid_event_list = [];
    current_event = null;

    add_event(event) {
        this.current_event.end();
        this.event_list.push_back(this.current_event);
        this.current_event = event;
        this.undid_event_list = [];
    }

    undo_event() {
        const event = this.done_event_list[0]
        event.undo();
        this.undid_event_list.push_back(event)
    }

    end_event() {
        this.current_event.end();
        this.event_list.push_back(this.current_event);
        this.current_event = null;
    }
}