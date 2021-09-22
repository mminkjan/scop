/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bmp_reader.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/21 17:57:03 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/09/22 18:12:36 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void  load_bmp(t_cop *scop, const char *imagepath)
{
    int             fd;
    int             i;
    unsigned int    datapos;
    unsigned int    width;
    unsigned int    height;
    unsigned int    image_size;

    unsigned char   *data;
    const char      *file;

    fd = open("resources/models/teapot.obj", O_RDONLY);
    if (fd == -1)
        scop_return_error(scop, "unable to open bmp file\n");
    file_to_string(scop, fd, &file);
    if ( file[0]!='B' || file[1]!='M' )
        scop_return_error(scop, "bmp file not wel formatted\n");
    close(fd);
    datapos = *(int*)&(file[0x0A]);
    image_size = *(int*)&(file[0x22]);
    width = *(int*)&(file[0x12]);
    height = *(int*)&(file[0x16]);
    
    if (image_size == 0)
        image_size = width * height * 3;
    if (datapos == 0)
        datapos = 54;
    data = (unsigned char*)malloc(sizeof(unsigned char) * image_size);
    fd = 54;
    i = 0;
    // while (i < image_size && file[fd] != NULL)
    // {
    //     data[i] = file[fd];
    //     i++;
    //     fd++;        
    // }
    free(&file);

    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);






    


    

    
}