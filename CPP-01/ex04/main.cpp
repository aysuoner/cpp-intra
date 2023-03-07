/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:34:19 by aoner             #+#    #+#             */
/*   Updated: 2023/03/07 23:31:14 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string ft_replace(std::string cont ,std::string find, std::string replace)
{
	size_t	pos = cont.find(find);
    while (pos != std::string::npos)
    {
        cont.erase(pos , find.length());
        cont.insert(pos, replace);
        pos = cont.find(find);
    }
    return cont;
}

std::ifstream file_check(std::string fileName)
{
	std::ifstream file(fileName);
	if (!file.is_open())
	{
		std::cout << "File cannot be opened" << std::endl;
		exit (EXIT_FAILURE);
	}
	return (file);
}

std::ofstream file_create(std::string fileName)
{
	std::ofstream newFile(fileName + ".replace", std::ios::trunc);
	if (!newFile.is_open())
	{
		std::cout << "File cannot be opened" << std::endl;
		exit(EXIT_FAILURE);
	}
	return (newFile);
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Usage: ./program [fileName] [search] [replace]" << std::endl;
		return 1;
	}
	if (strlen(argv[1]) && strlen(argv[2]) && strlen(argv[3]))
	{
		std::string fileName;
		std::ifstream file;
		std::string line;
		std::ofstream newFile;
	
		fileName = argv[1];
		file = file_check(fileName);
        std::getline(file, line, '\0');
		file.close();
		line = ft_replace(line, argv[2], argv[3]);
		newFile = file_create(fileName);
		newFile << line;
        newFile.close();
	}
	else
		std::cout << "Arguments cannot be empty" << std::endl;
	return (0);
}
