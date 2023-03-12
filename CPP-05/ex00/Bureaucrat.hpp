#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
	const std::string	name;
	int					grade;
public:
	//constructor
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &old_obj);

	//overloaded operator
	Bureaucrat &operator=(const Bureaucrat &old_obj);

	//destructor
	~Bureaucrat();

	//set
	void	setGrade(int grade);

	//get
	const std::string	&getName() const;
	int					getGrade() const;

	//public method
	void        incrementGrade();
    void        decrementGrade();

	//exception class
	/* GradeTooLowException sınıfı, std::exception sınıfını alt sınıf olarak tanımlar.
	Böylece, GradeTooLowException sınıfı, std::exception sınıfının tüm özelliklerine sahip olur.
	Bu şekilde, GradeTooLowException sınıfı, std::exception sınıfından kalıtım alarak,
	istisnaların yakalanması ve işlenmesi için standart bir arayüz sağlar.*/
	class GradeTooLowException: public std::exception
	{
  		public:
    		virtual const char* what() const _NOEXCEPT;
	};

	class GradeTooHighException: public std::exception
	{
		public:
    		virtual const char* what() const _NOEXCEPT;
	};
};

//ostream overload
std::ostream&   operator<<(std::ostream& out, const Bureaucrat& other);

#endif