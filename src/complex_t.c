#include "../header/complex_t.h"

error_t complexAdd(complex_t const* _Z1, complex_t const* _Z2, complex_t* _Z3){
    if( _Z1 == NULL|| _Z2 == NULL)
        return ERROR_NULL_PTR;
    
    _Z3->real = _Z1->real+_Z2->real;
    _Z3->imaginary = _Z1->imaginary + _Z2->imaginary;
    
    return SUCCESS;
}

error_t complexSub(complex_t const*  _Z1, complex_t const* _Z2, complex_t* _Z3){
    if( _Z1 == NULL|| _Z2 == NULL)
        return ERROR_NULL_PTR;
    
    _Z3->real = _Z1->real - _Z2->real;
    _Z3->imaginary = _Z1->imaginary - _Z2->imaginary;
    
    return SUCCESS;
}

error_t complexMul(complex_t const* _Z1, complex_t const* _Z2, complex_t* _Z3){
    
    if( _Z1 == NULL|| _Z2 == NULL)
        return ERROR_NULL_PTR;
    
    _Z3->real = (_Z1->real * _Z2->real) - (_Z1->imaginary * _Z2->imaginary);
    _Z3->imaginary = (_Z1->real * _Z2->imaginary) + (_Z1->imaginary * _Z2->real);
    
    return SUCCESS;
}

error_t complexDiv(complex_t const* _Z1, complex_t const* _Z2, complex_t* _Z3){
    if( _Z1 == NULL|| _Z2 == NULL)
        return ERROR_NULL_PTR;
    
    float divv = _Z2->imaginary*_Z2->imaginary + _Z2->real * _Z2->real;
    
    if(divv == 0)
        return ERROR_DIV_BY_ZERO;
    
    _Z3->real = ((_Z1->real * _Z2->real) + (_Z1->imaginary * _Z2->imaginary))/divv;
    _Z3->imaginary = ((_Z1->imaginary * _Z2->real) - (_Z1->real * _Z2->imaginary))/divv;
    
    return SUCCESS;
}