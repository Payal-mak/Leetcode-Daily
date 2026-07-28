/**
 * @return {Function}
 */
var createHelloWorld = function() {
    //arrow syntax
    return () => "Hello World";
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */