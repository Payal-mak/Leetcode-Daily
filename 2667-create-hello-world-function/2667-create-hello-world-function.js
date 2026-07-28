/**
 * @return {Function}
 */
var createHelloWorld = function() {
    //arrow syntax + Rest arguments
    return (...args) => "Hello World";
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */