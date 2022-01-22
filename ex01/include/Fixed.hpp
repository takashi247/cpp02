#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const int i_num);
		Fixed(const float f_num);
		Fixed(const Fixed &fixed);
		~Fixed();
		Fixed	&operator=(const Fixed &fixed);
		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	private:
		int							raw_value;
		static const int			frac_bit = 8;
		static const int			INT_MAX_FOR_FIXED = INT_MAX >> frac_bit;
		static const int			INT_MIN_FOR_FIXED = INT_MIN >> frac_bit;
		static const std::string	OVERFLOW_ERROR_MSG;
		static void					print_overflow_error();
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif