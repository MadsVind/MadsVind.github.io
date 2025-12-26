function remove_from_list(list, el) {
    const idx = list.indexOf(el);
    if (idx !== -1) list.splice(idx, 1);
    return list;
}

function check_approx(num1, num2, epsilon) {
    return Math.abs(num1 - num2) < epsilon;
}

window.remove_from_list = remove_from_list;
window.check_approx = check_approx;