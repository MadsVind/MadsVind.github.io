

class Event {
    ended = false;

    is_ended() {
        return this.ended;
    }

    end() {
        this.ended = true;
    }

    is_move_event() {
        return false;
    }

    is_write_event() {
        return false;
    }
} 