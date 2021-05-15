/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_shaders.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/08 00:39:47 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/05/15 15:14:49 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/scop.h"


void printShaderLog( GLuint shader )
{
    if( glIsShader( shader ) )
    {
        int infoLogLength = 0;
        int maxLength = infoLogLength;
        
        glGetShaderiv( shader, GL_INFO_LOG_LENGTH, &maxLength );
        
        char* infoLog = malloc(sizeof(char) * 1000);
        
        glGetShaderInfoLog( shader, maxLength, &infoLogLength, infoLog );
        if( infoLogLength > 0 )
            printf( "%s\n", infoLog );

        //Deallocate string
        // delete[] infoLog;
        else
            printf( "Name %d is not a shader\n", shader );
    }
}

void    fshader_to_string(t_cop *scop, int fd)
{
    int return_value;
    char *line;
    char *buffer;
    char *temp;
    
    return_value = get_next_line2(fd, &line);
    buffer = (char*)malloc(sizeof(char) * 1000);
    while (return_value > 0)
    {
        temp = ft_strjoin(buffer, line);
        buffer = ft_strcpy(buffer, temp);
        if (temp != NULL)
            free(temp);
        free(line);
        return_value = get_next_line2(fd, &line);
    }
    if (return_value < 0)
        scop_return_error(scop, "unable to read fragment shader\n");
    scop->shaders->fshader = ft_strdup(buffer);
    printf("fragment = %s\n", scop->shaders->fshader);
    free(buffer);
}

void    vshader_to_string(t_cop *scop, int fd)
{
    int return_value;
    char *line;
    char *buffer;
    char *temp;
    return_value = get_next_line2(fd, &line);
    buffer = (char*)malloc(sizeof(char) * 1000);
    ft_bzero(buffer, ft_strlen(buffer));
    while (return_value > 0)
    {
        temp = ft_strjoin(buffer, line);
        buffer = ft_strcpy(buffer, temp);
        if (temp != NULL)
            free(temp);
        free(line);
        return_value = get_next_line2(fd, &line);
    }
    if (return_value < 0)
        scop_return_error(scop, "unable to read vertex shader\n");
    scop->shaders->vshader = ft_strdup(buffer);
    printf("vertex = %s\n", scop->shaders->vshader);
    free(buffer);
}

GLuint load_shaders(t_cop *scop)
{
    GLuint shader_id_vertex;
    GLuint shader_id_fragment;
    GLint vShaderCompiled = GL_FALSE;
    int fd;
    
    shader_id_vertex = glCreateShader(GL_VERTEX_SHADER);
    shader_id_fragment = glCreateShader(GL_FRAGMENT_SHADER);
    fd = open("resources/shaders/basic.vertexshader", O_RDONLY);
    if (fd == -1)
        scop_return_error(scop, "unable to open vertex shader\n");
    vshader_to_string(scop, fd);
    close(fd);
    fd = open("resources/shaders/basic.fragmentshader", O_RDONLY);
    if (fd == -1)
        scop_return_error(scop, "unable to open fragment shader\n");
    fshader_to_string(scop, fd);
    close(fd);
    
    
    printf("%d - %d\n", shader_id_fragment, shader_id_vertex);
    glShaderSource(shader_id_vertex, 1, &scop->shaders->vshader, NULL);
    glCompileShader(shader_id_vertex);
    glGetShaderiv(shader_id_vertex, GL_COMPILE_STATUS, &vShaderCompiled );
    if( vShaderCompiled != GL_TRUE )
    {
        printf( "Unable to compile vertex shader!\n");
        printShaderLog( shader_id_vertex);
    }

    glShaderSource(shader_id_fragment, 1, &scop->shaders->fshader, NULL);
    glCompileShader(shader_id_fragment);
    glGetShaderiv(shader_id_fragment, GL_COMPILE_STATUS, &vShaderCompiled );
    if( vShaderCompiled != GL_TRUE )
    {
        printf( "Unable to compile fragment shader!\n");
        printShaderLog( shader_id_fragment );
    }
    
    glAttachShader(scop->program_id, shader_id_vertex);
	glAttachShader(scop->program_id, shader_id_fragment);
    glLinkProgram(scop->program_id);

	glDeleteShader(shader_id_vertex);
	glDeleteShader(shader_id_fragment);
    return (0);
}