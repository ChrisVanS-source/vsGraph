#pragma once

// Data types

enum DataType
{
    QFLOATING_POINT = 0,
    QINTEGER,
    QBOOLEAN,
    NUMBER_OF_TYPES, // This should always be last in case we add new types
    XXX = 999
};

inline DataType next_data_type(DataType dt)
{
    switch (dt)
    {
    case QFLOATING_POINT: return QINTEGER;
    case QINTEGER: return QBOOLEAN;
    case QBOOLEAN: return NUMBER_OF_TYPES;
    case NUMBER_OF_TYPES:
    case XXX:
        return XXX;
    }
    return XXX;
}


// List of operations

#define FUNC1_ENUM(A) \
    A, \
    A##_PX

#define FUNC2_ENUM(A) \
    A, \
    A##_PX, \
    A##_PY, \
    A##_PX_PY

enum ADType {

    NONE,
    FORWARD,
    BACKWARD

};


enum Operation {

    UNKNOWN,

    // Scalar related enums

    FUNC1_ENUM(EQUAL), 
    EQUAL_SCALAR,
    CHECKPOINT,
    FUNCTION,
    FUNC1_ENUM(SINE),
    FUNC1_ENUM(COSINE),
    FUNC1_ENUM(TANGENT),
    FUNC1_ENUM(ARC_SINE),
    FUNC1_ENUM(ARC_COSINE),
    FUNC1_ENUM(ARC_TANGENT),
    FUNC1_ENUM(LOGARITHM),
    FUNC1_ENUM(LOGARITHM2),
    FUNC1_ENUM(LOGARITHM10),
    FUNC1_ENUM(EXPONENTIAL),
    FUNC1_ENUM(HYPERBOLIC_SINE),
    FUNC1_ENUM(HYPERBOLIC_COSINE),
    FUNC1_ENUM(HYPERBOLIC_TANGENT),
    FUNC1_ENUM(SQUAREROOT),
    FUNC1_ENUM(COMPLEMENTARY_ERRORFUNC),
    FUNC1_ENUM(CEILING),
    FUNC1_ENUM(FLOORING),
    FUNC1_ENUM(HEAVISIDE_STEP),
    FUNC2_ENUM(POWER),
    FUNC1_ENUM(POWER_SCALAR),
    FUNC1_ENUM(SCALAR_POWER),
    FUNC2_ENUM(MULTIPLY),
    FUNC1_ENUM(MULTIPLY_SCALAR),
    FUNC2_ENUM(DIVIDE),
    FUNC1_ENUM(DIVIDE_SCALAR),
    FUNC1_ENUM(SCALAR_DIVIDE),
    FUNC2_ENUM(ADD),
    FUNC1_ENUM(ADD_SCALAR),
    FUNC2_ENUM(SUBTRACT),       // x and y are not scalar in x-y
    FUNC1_ENUM(SUBTRACT_SCALAR),// y is scalar in x-y
    FUNC1_ENUM(SCALAR_SUBTRACT),// x is scalar in x-y
    FUNC1_ENUM(CHANGE_SIGN),
    FUNC2_ENUM(MAXIMUM),
    FUNC1_ENUM(MAXIMUM_SCALAR), // No SCALAR_MAXIMUM due to symmetry
    FUNC2_ENUM(MINIMUM),
    FUNC1_ENUM(MINIMUM_SCALAR), // No SCALAR_MINIMUM due to symmetry
    EQUAL_TO,                   // z = x==y where x,y are qscalar
    GREATER_THAN,               // z = x > y where x,y are qscalar
    LESS_THAN,                  // z = x < y where x,y are qscalar
    EQUAL_TO_SCALAR,            // z = x == y where x is qscalar and y is number
    GREATER_THAN_SCALAR,        // z = x > y where x is qscalar and y is number
    LESS_THAN_SCALAR,           // z = x < y where x is qscalar and y is number
    FUNC2_ENUM(IFF),            // z = iff(c,x,y) where x,y are qscalar
    FUNC1_ENUM(IFF_SCALAR),     // z = iff(c,x,y) where x is qscalar and y is number
    IFF_SCALAR_SCALAR,          // z = iff(c,x,y) where x is qscalar and y are number

    // Boolean related enums

    BOOLEAN_EQUAL,              // z = x where x is qboolean
    BOOLEAN_EQUAL_BOOL,         // z = x where x is bool 
    BOOLEAN_AND,                // z = x && y where x and y are qboolean
    BOOLEAN_AND_BOOL,           // z = x && y where x is qboolean and y is bool
    BOOLEAN_OR,                 // z = x || y where x and y are qboolean
    BOOLEAN_OR_BOOL,            // z = x || y where x is qboolean and y is bool
    BOOLEAN_NOT,                // z = !x where x is qboolean
    BOOLEAN_EQUAL_TO,           // z = x == y where x and y are qboolean
    BOOLEAN_EQUAL_TO_BOOL,      // z = x == y where x is qboolean and y is bool
    BOOLEAN_IFF,                // z = if(c,x,y) where c,x,y are qboolean
    BOOLEAN_IFF_BOOL,           // z = if(c,x,y) where c,x are qboolean and y is bool
    BOOLEAN_IFF_BOOL_BOOL,      // z = if(c,x,y) where c is qboolean and x,y are bool

    // Integer related enums

    INTEGER_EQUAL,              // z = x where x is qinteger
    INTEGER_EQUAL_INT,          // z = x where x is int
    INTEGER_ADD,                // z = x + y where x,y are qinteger
    INTEGER_SUBTRACT,           // z = x - y where x,y are qinteger
    INTEGER_MULTIPLY,           // z = x * y where x,y are qinteger
    INTEGER_DIVIDE,             // z = x / y where x,y are qinteger
    INTEGER_ADD_INT,            // z = x + y where x is qinteger and y is int
    INTEGER_SUBTRACT_INT,       // z = x - y where x is qinteger and y is int
    INTEGER_INT_SUBTRACT,       // z = x - y where x is int and y is qinteger
    INTEGER_MULTIPLY_INT,       // z = x * y where x is qinteger and y is int
    INTEGER_DIVIDE_INT,         // z = x / y where x is qinteger and y is int
    INTEGER_INT_DIVIDE,         // z = x / y where x is int and y is qinteger
    INTEGER_EQUAL_TO,           // z = x == y where x,y are qinteger
    INTEGER_EQUAL_TO_INT,       // z = x == y where x is qinteger and y is int
    INTEGER_LESS_THAN,          // z = x < y where x,y are qinteger
    INTEGER_LESS_THAN_INT,      // z = x < y where x is qinteger and y is int
    INTEGER_GREATER_THAN,       // z = x > y where x,y are qinteger
    INTEGER_GREATER_THAN_INT,   // z = x > y where x is qinteger and y is int
    INTEGER_IFF,                // z = if(c,x,y) where x,y are qinteger
    INTEGER_IFF_INT,            // z = if(c,x,y) where x is qinteger and y is int
    INTEGER_IFF_INT_INT,        // z = if(c,x,y) where x, y are int
    INTEGER_CHANGE_SIGN,         // z = -x where x is qinteger

    // Algorithm related enums

    STD_LOWER_BOUND,
    STD_LOWER_BOUND_SCALAR,
    BRACKET

};

#define MAP_FUNC1(A) A: return xp ? A##_PX : A; \
                case A##_PX: return xp ? A##_PX : UNKNOWN

#define MAP_FUNC2(A) A: return (xp && yp ? A##_PX_PY : (xp ? A##_PX : (yp ? A##_PY : A))); \
                case A##_PX: return xp && !yp ? A##_PX : UNKNOWN; \
                case A##_PY: return !xp && yp ? A##_PY : UNKNOWN; \
                case A##_PX_PY: return xp && yp ? A##_PX_PY : UNKNOWN

#define FWD_FUNC1(A) A: case A##_PX

#define FWD_FUNC2(A) A: case A##_PX: case A##_PY: case A##_PX_PY
