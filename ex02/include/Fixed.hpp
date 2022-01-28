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
		Fixed				&operator=(const Fixed &fixed);
		bool				operator<(const Fixed &rhs) const;
		bool				operator>(const Fixed &rhs) const;
		bool				operator>=(const Fixed &rhs) const;
		bool				operator<=(const Fixed &rhs) const;
		bool				operator==(const Fixed &rhs) const;
		bool				operator!=(const Fixed &rhs) const;
		Fixed				operator+(const Fixed &rhs) const;
		Fixed				operator-(const Fixed &rhs) const;
		Fixed				operator*(const Fixed &rhs) const;
		Fixed				operator/(const Fixed &rhs) const;
		Fixed				&operator++();
		Fixed				operator++(int);
		Fixed				&operator--();
		Fixed				operator--(int);
		static Fixed		&min(Fixed &lhs, Fixed &rhs);
		static const Fixed	&min(const Fixed &lhs, const Fixed &rhs);
		static Fixed		&max(Fixed &lhs, Fixed &rhs);
		static const Fixed	&max(const Fixed &lhs, const Fixed &rhs);
		int					getRawBits() const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
		static const int	EIGHT_BIT_MASK = 255;
	private:
		int							raw_value;
		static const int			frac_bit = 8;
		static const int			INT_MAX_FOR_FIXED = INT_MAX >> frac_bit;
		static const int			INT_MIN_FOR_FIXED = INT_MIN >> frac_bit;
		static const std::string	OVERFLOW_ERROR_MSG;
		static const std::string	DIVISION_BY_ZERO_MSG;
		static void					print_overflow_error();
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
