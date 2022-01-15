#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const int i_num);
		Fixed(const float f_num);
		Fixed(const Fixed& fixed);
		~Fixed();
		Fixed& operator=(const Fixed& fixed);
		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	private:
		int					raw_value;
		static const int	frac_bit = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif