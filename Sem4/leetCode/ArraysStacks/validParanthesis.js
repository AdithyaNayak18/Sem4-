var isValid = function(s) {
    var stack = [];
    var start = ["(", "[", "{"];
    for (let val in s) {
        let elem = s[val];
        if (start.includes(elem)) {
            stack.push(elem);
        } else if (elem === "]" || elem === ")" || elem === '}') {
            let last = stack.pop();
            switch (elem) {
                case "}":
                    if (last !== "{")
                        return false;
                    break;
                case "]":
                    if (last !== "[")
                        return false;
                    break;
                case ")":
                    if (last !== "(")
                        return false;
                    break;
                default:
            }
        }
    }
    return stack.length === 0;
};
