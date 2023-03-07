/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:48:38 by aoner             #+#    #+#             */
/*   Updated: 2023/03/07 18:01:15 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/* !!!Silah sınıfının yapıcısı, type özniteliğini başlatmak için
parametre olarak std::string'e const başvurusu alır.
!!!Düz std::string parametresi yerine const başvurusu kullanmanın nedeni,
dize verilerinin gereksiz yere kopyalanmasını önlemektir.
Bir std::string'i değere göre geçirmek, özellikle büyük dizeler için
performans ve bellek kullanımı açısından maliyetli olabilen dizenin bir kopyasının yapılmasına neden olur.
Bir const başvurusu kullanarak, bir kopya yapmadan dizeyi geçirebiliriz ve işlev, dizeyi değiştirmeden
dizenin verilerine erişebilir.
!!!Ayrıca, reference const yapmak, işlevin iletilmekte olan dizeyi değiştirememesini sağlar.
Bu, güvenlik için önemlidir ve orijinal dizedin işlev dışındaki istenmeyen değişikliklerin önlenmesine yardımcı olabilir. */
Weapon::Weapon(const std::string &type)
{
	this->type = type;
}

Weapon::~Weapon()
{
}

const std::string& Weapon::getType()
{
	return type;
}

/* Bir const başvurusu kullanarak, bir kopya oluşturmadan yeni türü iletebiliriz
ve işlev, dizenin verilerine onu değiştirmeden erişebilir.
Ayrıca, referans const yapmak, işlevin iletilmekte olan yeni türü değiştirememesini sağlar.
Bu, işlevin dışındaki dizelerde istenmeyen değişikliklerini önlemeye yardımcı olabilir.*/
void Weapon::setType(const std::string &type)
{
	this->type = type;
}
