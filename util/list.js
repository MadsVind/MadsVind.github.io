function remove(list, el) {
    const idx = list.indexOf(el);
    if (idx !== -1) list.splice(idx, 1);
    return list;
}

window.remove = remove;