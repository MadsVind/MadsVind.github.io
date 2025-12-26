class ChangeHandler {
    done_change_stack   = [];
    undone_change_stack = [];

    add(change) {
        this.done_change_stack.push(change);
        this.undone_change_stack = [];
    }

    undo() {
        if (this.done_change_stack.length == 0) return;
        const change = this.done_change_stack.pop();
        change.undo();
        this.undone_change_stack.push(change);
    }

    redo() {
        if (this.undone_change_stack.length == 0) return;
        console.log(this.undone_change_stack);
        const change = this.undone_change_stack.pop();
        change.do();
        this.done_change_stack.push(change);
    }
}