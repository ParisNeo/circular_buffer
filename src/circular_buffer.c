
/**
 * \file        linalg.c
 * \brief       A small linear algebra library
 * \author      Saifeddine ALOUI
 * \version     0.1
 * \date        11 juin 2022
 *
 * A linear algebra library to use matrices in c.
 *
 */
#include <circular_buffer.h>
#include <stdlib.h>
#include <stdio.h>
// Defines -----------------------------------------------

// Structs -----------------------------------------------
// Functions --------------------------------------------

/**
 * \fn void icb_init(iCircularBuffer *buffer, int size)
 * \brief Creates an integer buffer object.
 *
 * \param buffer A pointer to the buffer object 
 * \param size The size of the buffer (at most MAX_CIRCULARBUFFER_SIZE).
 * \return Nothing
 */
void icb_init(iCircularBuffer *buffer, int size)
{
	buffer->count=0;
	buffer->size=size;
	buffer->head=0;
	buffer->data = (int*)malloc(size*sizeof(int));
	for(int i=0;i<size;i++)
		buffer->data[i]=0;
}

/**
 * \fn void fcb_init(fCircularBuffer *buffer, int size)
 * \brief Creates a float buffer object.
 *
 * \param buffer A pointer to the buffer object 
 * \param size The size of the buffer (at most MAX_CIRCULARBUFFER_SIZE).
 * \return Nothing
 */
void fcb_init(fCircularBuffer *buffer, int size)
{
	buffer->count=0;
	buffer->size=size;
	buffer->head=0;
	buffer->data = (int*)malloc(size*sizeof(float));
	for(int i=0;i<size;i++)
		buffer->data[i]=0.0f;
}


/**
 * \fn void icb_delete(iCircularBuffer *buffer, int size)
 * \brief Deletes an integer buffer object.
 *
 * \param buffer A pointer to the buffer object 
 * \param size The size of the buffer (at most MAX_CIRCULARBUFFER_SIZE).
 * \return Nothing
 */
void icb_delete(iCircularBuffer *buffer)
{
	buffer->count=0;
	buffer->size=0;
	buffer->head=0;
	free(buffer->data); 
	buffer->data = (int*)0;
}

/**
 * \fn void fcb_delete(fCircularBuffer *buffer, int size)
 * \brief Deletes a float buffer object.
 *
 * \param buffer A pointer to the buffer object 
 * \param size The size of the buffer (at most MAX_CIRCULARBUFFER_SIZE).
 * \return Nothing
 */
void fcb_delete(fCircularBuffer *buffer)
{
	buffer->count=0;
	buffer->size=0;
	buffer->head=0;
	free(buffer->data); 
	buffer->data = (float*)0;
}


// Adding data to the buffer -----------------------

/**
 * \fn void icb_push(iCircularBuffer *buffer, int value)
 * \brief Pushes a value to the buffer.
 *
 * \param buffer A pointer to the buffer object 
 * \param value  The value to be pushed
 * \return Nothing
 */
void icb_push(iCircularBuffer *buffer, int value)
{
	buffer->data[buffer->head]=value;
	if(buffer->count<buffer->size)
		buffer->count++;
	if(buffer->head<buffer->size-1)
		buffer->head++;
	else
		buffer->head=0;
}

/**
 * \fn void fcb_push(fCircularBuffer *buffer, float value)
 * \brief Pushes a value to the buffer.
 *
 * \param buffer A pointer to the buffer object 
 * \param value  The value to be pushed
 * \return Nothing
 */
void fcb_push(fCircularBuffer *buffer, float value)
{
	buffer->data[buffer->head]=value;
	if(buffer->count<buffer->size)
		buffer->count++;
	if(buffer->head<buffer->size-1)
		buffer->head++;
	else
		buffer->head=0;
}

// Computing statistics --------------------------------------
/**
 * \fn void icb_mean(iCircularBuffer *buffer)
 * \brief Gets the mean of the buffer values.
 *
 * \param buffer A pointer to the buffer object 
 * \return The mean value
 */
float icb_mean(fCircularBuffer *buffer)
{
	float sum=0.0f;
	if(buffer->count<=0)
		return 0;
	
	for(int i=0;i<buffer->count;i++)
	{
		sum += buffer->data[i];
	}
	return sum/buffer->count;
}


/**
 * \fn void fcb_mean(fCircularBuffer *buffer)
 * \brief Gets the mean of the buffer values.
 *
 * \param buffer A pointer to the buffer object 
 * \return The mean value
 */
float fcb_mean(fCircularBuffer *buffer)
{
	float sum=0.0f;
	if(buffer->count<=0)
		return 0;
	
	for(int i=0;i<buffer->count;i++)
	{
		sum += buffer->data[i];
	}
	return sum/buffer->count;
}


/**
 * \fn void fcb_max(fCircularBuffer *buffer)
 * \brief Gets the max of the buffer values.
 *
 * \param buffer A pointer to the buffer object 
 * \return The mean value
 */
int icb_max(iCircularBuffer *buffer)
{
	int max;
	if(buffer->count<=0)
		return 0;
	max = buffer->data[0];
	for(int i=1;i<buffer->count;i++)
	{
		if(buffer->data[i]>max)
		{
			max = buffer->data[i];
		}
	}
	return max;
}

/**
 * \fn void fcb_max(fCircularBuffer *buffer)
 * \brief Gets the max of the buffer values.
 *
 * \param buffer A pointer to the buffer object 
 * \return The mean value
 */
float fcb_max(fCircularBuffer *buffer)
{
	float max;
	if(buffer->count<=0)
		return 0;
	max = buffer->data[0];
	for(int i=1;i<buffer->count;i++)
	{
		if(buffer->data[i]>max)
		{
			max = buffer->data[i];
		}
	}
	return max;
}



/**
 * \fn void icb_min(iCircularBuffer *buffer)
 * \brief Gets the min of the buffer values.
 *
 * \param buffer A pointer to the buffer object 
 * \return The mean value
 */
int icb_min(iCircularBuffer *buffer)
{
	int min;
	if(buffer->count<=0)
		return 0;
	min = buffer->data[0];
	for(int i=1;i<buffer->count;i++)
	{
		if(buffer->data[i]<min)
		{
			min = buffer->data[i];
		}
	}
	return min;
}

/**
 * \fn void fcb_min(fCircularBuffer *buffer)
 * \brief Gets the min of the buffer values.
 *
 * \param buffer A pointer to the buffer object 
 * \return The mean value
 */
float fcb_min(fCircularBuffer *buffer)
{
	float min;
	if(buffer->count<=0)
		return 0;
	min = buffer->data[0];
	for(int i=1;i<buffer->count;i++)
	{
		if(buffer->data[i]<min)
		{
			min = buffer->data[i];
		}
	}
	return min;
}




/**
 * \fn void fcb_argmax(fCircularBuffer *buffer)
 * \brief Gets the argmax of the buffer values.
 *
 * \param buffer A pointer to the buffer object 
 * \return The mean value
 */
int icb_argmax(iCircularBuffer *buffer)
{
	int argmax;
	int max;
	if(buffer->count<=0)
		return 0;
	max = buffer->data[0];
	argmax = 0;
	for(int i=1;i<buffer->count;i++)
	{
		if(buffer->data[i]>max)
		{
			max = buffer->data[i];
			argmax = i;
		}
	}
	return max;
}

/**
 * \fn void fcb_argmax(fCircularBuffer *buffer)
 * \brief Gets the argmax of the buffer values.
 *
 * \param buffer A pointer to the buffer object 
 * \return The mean value
 */
int fcb_argmax(fCircularBuffer *buffer)
{
	int argmax;
	float max;
	if(buffer->count<=0)
		return 0;
	max = buffer->data[0];
	argmax = 0;
	for(int i=1;i<buffer->count;i++)
	{
		if(buffer->data[i]>max)
		{
			max = buffer->data[i];
			argmax = i;
		}
	}
	return argmax;
}

/**
 * \fn void icb_argmin(fCircularBuffer *buffer)
 * \brief Gets the argmin of the buffer values.
 *
 * \param buffer A pointer to the buffer object 
 * \return The mean value
 */
int icb_argmin(iCircularBuffer *buffer)
{
	int argmin;
	int min;
	if(buffer->count<=0)
		return 0;
	min = buffer->data[0];
	for(int i=1;i<buffer->count;i++)
	{
		if(buffer->data[i]<min)
		{
			min = buffer->data[i];
			argmin = i;
		}
	}
	return argmin;
}

/**
 * \fn void fcb_argmin(fCircularBuffer *buffer)
 * \brief Gets the argmin of the buffer values.
 *
 * \param buffer A pointer to the buffer object 
 * \return The mean value
 */
int fcb_argmin(fCircularBuffer *buffer)
{
	int argmin;
	float min;
	if(buffer->count<=0)
		return 0;
	min = buffer->data[0];
	argmin = 0;
	for(int i=1;i<buffer->count;i++)
	{
		if(buffer->data[i]<min)
		{
			min = buffer->data[i];
			argmin = i;
		}
	}
	return argmin;
}


/**
 * \fn int icb_get_at(iCircularBuffer *buffer, int pos)
 * \brief get value at position pos in the time reference (0 is the oldest value in the buffer)
 *
 * \param buffer A pointer to the buffer object
 * \param pos the discrete time position of the value to be recovered
 * \return the value at the position pos
 */
int icb_get_at(iCircularBuffer *buffer, int pos)
{
	return buffer->data[(buffer->head+pos)%buffer->size];
}

/**
 * \fn float fcb_get_at(fCircularBuffer *buffer, int pos)
 * \brief get value at position pos in the time reference (0 is the oldest value in the buffer)
 *
 * \param buffer A pointer to the buffer object
 * \param pos the discrete time position of the value to be recovered
 * \return the value at the position pos
 */
float fcb_get_at(fCircularBuffer *buffer, int pos)
{
	return buffer->data[(buffer->head+pos)%buffer->size];
}

/**
 * \fn void fcb_straighten(iCircularBuffer *buffer, iCircularBuffer *straightened_buffer)
 * \brief Makes a straightened copy of a buffer. A straightened buffer has the oldest value in position 0 and latest on position head==count.
 *
 * \param buffer A pointer to the buffer object to be straightened
 * \param buffer A pointer to the buffer object to contyain the straightened data
 * \return The mean value
 */
void icb_straightened_copy(iCircularBuffer *buffer, iCircularBuffer *straightened_buffer)
{
	int pos = buffer->head;
	straightened_buffer->count = buffer->count;
	straightened_buffer->head = buffer->count;
	for(int i=0;i<buffer->count;i++)
	{
		straightened_buffer->data[i] = buffer->data[pos];
		if(pos<buffer->count-1)
		{
			pos ++;
		}
		else
		{
			pos =0;
		}
	}
}

/**
 * \fn void fcb_straighten(fCircularBuffer *buffer, fCircularBuffer *straightened_buffer)
 * \brief Makes a straightened copy of a buffer. A straightened buffer has the oldest value in position 0 and latest on position head==count.
 *
 * \param buffer A pointer to the buffer object to be straightened
 * \param buffer A pointer to the buffer object to contyain the straightened data
 * \return The mean value
 */
void fcb_straightened_copy(fCircularBuffer *buffer, fCircularBuffer *straightened_buffer)
{
	int pos = buffer->head;
	straightened_buffer->count = buffer->count;
	straightened_buffer->head = buffer->count;
	for(int i=0;i<buffer->count;i++)
	{
		straightened_buffer->data[i] = buffer->data[pos];
		if(pos<buffer->count-1)
		{
			pos ++;
		}
		else
		{
			pos =0;
		}
	}
}


/**
 * \fn int icb_absoluteindex_to_timeindex(iCircularBuffer *buffer, int absolute_index)
 * \brief Converts absolute index into time index
 *
 * \param buffer A pointer to the buffer object 
 * \return The mean value
 */
int icb_absoluteindex_to_timeindex(iCircularBuffer *buffer, int absolute_index)
{
	return absolute_index>buffer->head?absolute_index-buffer->head:buffer->count-buffer->head+absolute_index;
}

/**
 * \fn int icb_timeindex_to_absoluteindex(iCircularBuffer *buffer, int absolute_index)
 * \brief Converts time index into absolute index
 *
 * \param buffer A pointer to the buffer object 
 * \return The mean value
 */
int icb_timeindex_to_absoluteindex(iCircularBuffer *buffer, int time_index)
{
	return (buffer->head+time_index)%buffer->count;
}

/**
 * \fn int fcb_absoluteindex_to_timeindex(fCircularBuffer *buffer, int absolute_index)
 * \brief Converts absolute index into time index
 *
 * \param buffer A pointer to the buffer object 
 * \return The mean value
 */
int fcb_absoluteindex_to_timeindex(fCircularBuffer *buffer, int absolute_index)
{
	return absolute_index>buffer->head?absolute_index-buffer->head:buffer->count-buffer->head+absolute_index;
}

/**
 * \fn int fcb_timeindex_to_absoluteindex(fCircularBuffer *buffer, int absolute_index)
 * \brief Converts time index into absolute index
 *
 * \param buffer A pointer to the buffer object 
 * \return The mean value
 */
int fcb_timeindex_to_absoluteindex(fCircularBuffer *buffer, int time_index)
{
	return (buffer->head+time_index)%buffer->count;
}


/**
 * \fn icb_remove_at_timeindex(iCircularBuffer *buffer, int position
 * \brief Removes a value at a specific index (please consider straightening the buffer if you want to remove at timed position)
 *
 * \param buffer A pointer to the buffer object
 * \param index index of the value to be removed
 * \return Nothing
 */
void icb_remove_at_timeindex(iCircularBuffer *buffer, int index)
{
	int pos = buffer->head;
	while(index<buffer->count)
	{
		buffer[index]=buffer[index+1];
		index ++;
	}
	buffer->count--;
}

/**
 * \fn fcb_remove_at_timeindex(fCircularBuffer *buffer, int position
 * \brief Removes a value at a specific index (please consider straightening the buffer if you want to remove at timed position)
 *
 * \param buffer A pointer to the buffer object
 * \param index index of the value to be removed
 * \return Nothing
 */
void fcb_remove_at_timeindex(fCircularBuffer *buffer, int index)
{
	int pos = buffer->head;
	while(index<buffer->count)
	{
		buffer[index]=buffer[index+1];
		index ++;
	}
	buffer->count--;
}