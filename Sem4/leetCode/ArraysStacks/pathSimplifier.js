/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
    var stack=[];
    const dirs=path.split("/");
    for(let elem of dirs)
    {
        switch(elem)
        {
            case ".":
            case "": continue;
            break;
            case "..": if(stack) stack.pop();
            break;
            default: stack.push(elem);
        }
    }
    return "/" + stack.join("/");
};
