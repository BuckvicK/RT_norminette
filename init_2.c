/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:10:50 by chorange          #+#    #+#             */
/*   Updated: 2019/07/31 13:49:46 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		texture_init_1(t_rtv1 *rtv1)
{
	rtv1->textures[0] = SDL_LoadBMP("tex1.bmp");
	rtv1->textures[1] = SDL_LoadBMP("tex2.bmp");
	rtv1->textures[2] = SDL_LoadBMP("tex3.bmp");
	rtv1->textures[3] = SDL_LoadBMP("tex4.bmp");
	rtv1->textures[4] = SDL_LoadBMP("tex5.bmp");
	rtv1->tex = clCreateBuffer(rtv1->context, CL_MEM_READ_WRITE,
		1024 * 1024 * 3, NULL, &rtv1->ret);
	rtv1->ret = clEnqueueWriteBuffer(rtv1->command_queue,
		rtv1->tex, CL_TRUE, 0, 1024 * 1024 * 3,
		(unsigned char *)rtv1->textures[0]->pixels, 0, NULL, NULL);
	rtv1->ret = clSetKernelArg(rtv1->kernel, 2,
		sizeof(cl_mem), (void *)&rtv1->tex);
}

void		texture_init_2(t_rtv1 *rtv1)
{
	rtv1->tex = clCreateBuffer(rtv1->context, CL_MEM_READ_WRITE,
		1024 * 1024 * 3, NULL, &rtv1->ret);
	rtv1->ret = clEnqueueWriteBuffer(rtv1->command_queue,
		rtv1->tex, CL_TRUE, 0, 1024 * 1024 * 3,
		(unsigned char *)rtv1->textures[1]->pixels, 0, NULL, NULL);
	rtv1->ret = clSetKernelArg(rtv1->kernel, 3,
		sizeof(cl_mem), (void *)&rtv1->tex);
	rtv1->tex = clCreateBuffer(rtv1->context, CL_MEM_READ_WRITE,
		1024 * 1024 * 3, NULL, &rtv1->ret);
	rtv1->ret = clEnqueueWriteBuffer(rtv1->command_queue,
		rtv1->tex, CL_TRUE, 0, 1024 * 1024 * 3,
		(unsigned char *)rtv1->textures[2]->pixels, 0, NULL, NULL);
	rtv1->ret = clSetKernelArg(rtv1->kernel, 4,
		sizeof(cl_mem), (void *)&rtv1->tex);
}

void		texture_init_3(t_rtv1 *rtv1)
{
	rtv1->tex = clCreateBuffer(rtv1->context, CL_MEM_READ_WRITE,
		1024 * 1024 * 3, NULL, &rtv1->ret);
	rtv1->ret = clEnqueueWriteBuffer(rtv1->command_queue,
		rtv1->tex, CL_TRUE, 0, 1024 * 1024 * 3,
		(unsigned char *)rtv1->textures[3]->pixels, 0, NULL, NULL);
	rtv1->ret = clSetKernelArg(rtv1->kernel, 5,
		sizeof(cl_mem), (void *)&rtv1->tex);
	rtv1->tex = clCreateBuffer(rtv1->context, CL_MEM_READ_WRITE,
		1024 * 1024 * 3, NULL, &rtv1->ret);
	rtv1->ret = clEnqueueWriteBuffer(rtv1->command_queue,
		rtv1->tex, CL_TRUE, 0, 1024 * 1024 * 3,
		(unsigned char *)rtv1->textures[4]->pixels, 0, NULL, NULL);
	rtv1->ret = clSetKernelArg(rtv1->kernel, 6,
		sizeof(cl_mem), (void *)&rtv1->tex);
}

void		kernel_init(t_rtv1 *rtv1)
{
	rtv1->ret = clGetPlatformIDs(1, &rtv1->platform_id,
		&rtv1->ret_num_platforms);
	rtv1->ret = clGetDeviceIDs(rtv1->platform_id, CL_DEVICE_TYPE_GPU,
		1, &rtv1->device_id, &rtv1->ret_num_devices);
	rtv1->context = clCreateContext(NULL, 1, &rtv1->device_id, NULL,
		NULL, &rtv1->ret);
	rtv1->command_queue = clCreateCommandQueue(rtv1->context,
		rtv1->device_id, 0, &rtv1->ret);
	compile_from_file("kernels/kernel.cl", rtv1);
	rtv1->kernel = clCreateKernel(rtv1->program, "mishania", &rtv1->ret);
	rtv1->memobj = clCreateBuffer(rtv1->context, CL_MEM_READ_WRITE,
		CW * CH * 4, NULL, &rtv1->ret);
	rtv1->utils_memobj = clCreateBuffer(rtv1->context,
		CL_MEM_READ_WRITE, sizeof(t_scene), NULL, &rtv1->ret);
	rtv1->global_work_size = CW * CH;
	texture_init_1(rtv1);
	texture_init_2(rtv1);
	texture_init_3(rtv1);
}
