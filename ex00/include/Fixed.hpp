#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& fixed);
		~Fixed();
		Fixed& operator=(const Fixed& fixed);
		int		getRawBits() const;
		void	setRawBits(int const raw);
	private:
		int					i_num;
		static const int	frac_bit = 8;
};

#endif