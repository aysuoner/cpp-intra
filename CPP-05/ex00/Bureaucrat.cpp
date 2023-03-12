/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:23:34 by aoner             #+#    #+#             */
/*   Updated: 2023/03/12 14:53:41 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//Constructor
Bureaucrat::Bureaucrat(): name("default"), grade(1) {}

/* Class içinde tanımlanan name const olarak tanımlanmıştır.
Bu da değişkenin değerinin class dışında değiştirilmemesinin garanti edilmesini amaçlar. READONLY
&name olarak gönderilmesi ile veri transferinde daha verimli bir yapı kullanılmış olur
çünkü bu şekilde referansını göndermiş oluyoruz yani bir değişkeni kopyalamadan doğrudan değişkenin kendisini aktarmış olduk.*/
Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &old_obj): name(old_obj.name + "_copy"), grade(old_obj.grade)
{
	std::cout << "Bureaucrat Copy Constructor has been called" << std::endl;
}

//Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Deconstructor for " << this->getName() << " called" << std::endl;
}

//Operator overloaded
/* eğer name değişkeni const olarak işaretlenmişse ve name değerinin değiştirilmemesi garanti edilmişse,
copy assignment operator fonksiyonunda name = other.name şeklinde bir satır yazmanız gerekmez.
Zaten garanti edilen bir değerin değiştirilmesi yanlış olur ve bu durum hatalı kod yapısına neden olabilir.
const olarak işaretlenmişse bu durumda, name değişkeninin değeri copy assignment operator fonksiyonu çağrılmadan
önce verilmiş olan değer ile aynı kalır ve değiştirilemez.
*/
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &old_obj)
{
	std::cout << "Copy assignment operator has been called" << std::endl;
	if (this == &old_obj)
		return *this;
	this->grade = old_obj.getGrade();
	return *this;
}

//Setter
/* throw ifadeleri, fonksiyonun çağrıldığı yerde oluşabilecek hataları belirtmek için kullanılır.
Burada, grade değerinin sınırlarının dışına çıkması durumunda
iki farklı türde hata fırlatılıyor: GradeTooLowException ve GradeTooHighException.
Bu hatalar, programın beklenmedik şekilde çökmesini veya yanlış sonuçlar üretmesini önlemek için kullanılır.
Exit kullansaydım, hata durumlarında programın kontrolsüz bir şekilde sonlanmasına neden olabilir ve hata ayıklamayı zorlaştırabilir.
Return kullanmak hatanın neden olduğu durumdan çıkamayacağınız, yani işlemi durdurmanız gereken durumlarda yetersiz kalabilir.
Bu nedenle, throw kullanmak, hatanın neden olduğu durumu tespit etmek ve programın durdurulmasını sağlamak için
daha doğru bir yaklaşım olacaktır. */
void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade = grade;
}

//Getter
/*Const türde bir değişkenin değeri değiştirilemez
bu nedenle fonksiyonun dışında bu değişkeni kullanmak için
const referansı kullanmak daha verimlidir.
 Bu tanımlama, fonksiyonun döndürdüğü değerin bellekte referans olarak
 kullanılmasını sağlar. Bunun sonucu, fonksiyon döndürmüş olduğu değerin
 herhangi bir şekilde değiştirilmemesi garanti edilir ve bu değerin verileri
 bellekte bir kez tanımlanması yeterlidir.*/
const std::string &Bureaucrat::getName() const
{
	return(this->name);
}

int	Bureaucrat::getGrade() const
{
	return(this->grade);
}

//Exeptions
const char* Bureaucrat::GradeTooLowException::what() const _NOEXCEPT
{
	return ("Grade too low\n");
}

const char* Bureaucrat::GradeTooHighException::what() const _NOEXCEPT
{
	return ("Grade too high\n");
}

//Public method
void    Bureaucrat::incrementGrade()
{
	this->setGrade(this->grade - 1);
}

void    Bureaucrat::decrementGrade()
{
    this->setGrade(this->grade + 1);
}

//Ostream overload
std::ostream& operator<<(std::ostream& out, const Bureaucrat& other)
{
    out << other.getName() << ", bureaucrat grade " << other.getGrade();
    return out;
}