/**
 * @return {Function}
 */
var createHelloWorld = function() {
    //function syntax
    return function(...args) {
        return "Hello World";
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */