#ifndef FT_ABS_H
# define FT_ABS_H

// If the past value is negative, the value is converted to positive
# define ABS(Value) (Value < 0 ? -Value : Value)

#endif