
/**
 * \file        linalg.h
 * \brief       A small circular buffer library
 * \author      Saifeddine ALOUI
 * \version     0.1
 * \date        22 juin 2022
 *
 * A linear algebra library to use matrices in c.
 *
 */
#ifndef __linalg__
#define __linalg__
// Defines -----------------------------------------------

// Structs -----------------------------------------------
// An  int buffer structure
typedef struct {
	int size;
	int count;
	int head;
	int *data;

}iCircularBuffer;

// A float buffer structure
typedef struct {
	int size;
	int count;
	int head;
	float *data;

}fCircularBuffer;



// Prototypes --------------------------------------------

/**
 * \fn void icb_init(iCircularBuffer *buffer, int size)
 * \brief Creates an integer buffer object.
 *
 * \param buffer A pointer to the buffer object 
 * \param size The size of the buffer (at most MAX_CIRCULARBUFFER_SIZE).
 * \return Nothing
 */
void icb_init(iCircularBuffer *buffer, int size);

/**
 * \fn void fcb_init(fCircularBuffer *buffer, int size)
 * \brief Creates a float buffer object.
 *
 * \param buffer A pointer to the buffer object 
 * \param size The size of the buffer (at most MAX_CIRCULARBUFFER_SIZE).
 * \return Nothing
 */
void fcb_init(fCircularBuffer *buffer, int size);

// Adding data to the buffer -----------------------

/**
 * \fn void icb_push(iCircularBuffer *buffer, int value)
 * \brief Pushes a value to the buffer.
 *
 * \param buffer A pointer to the buffer object 
 * \param value  The value to be pushed
 * \return Nothing
 */
void icb_push(iCircularBuffer *buffer, int value);

/**
 * \fn void fcb_push(fCircularBuffer *buffer, float value)
 * \brief Pushes a value to the buffer.
 *
 * \param buffer A pointer to the buffer object 
 * \param value  The value to be pushed
 * \return Nothing
 */
void fcb_push(fCircularBuffer *buffer, float value);

// Computing statistics --------------------------------------
/**
 * \fn void icb_mean(iCircularBuffer *buffer)
 * \brief Gets the mean of the buffer values.
 *
 * \param buffer A pointer to the buffer object 
 * \return The mean value
 */
float icb_mean(fCircularBuffer *buffer);

/**
 * \fn void fcb_mean(fCircularBuffer *buffer)
 * \brief Gets the mean of the buffer values.
 *
 * \param buffer A pointer to the buffer object 
 * \return The mean value
 */
float fcb_mean(fCircularBuffer *buffer);


/**
 * \fn void fcb_max(fCircularBuffer *buffer)
 * \brief Gets the max of the buffer values.
 *
 * \param buffer A pointer to the buffer object 
 * \return The mean value
 */
int icb_max(iCircularBuffer *buffer);

/**
 * \fn void fcb_max(fCircularBuffer *buffer)
 * \brief Gets the max of the buffer values.
 *
 * \param buffer A pointer to the buffer object 
 * \return The mean value
 */
float fcb_max(fCircularBuffer *buffer);

/**
 * \fn void icb_min(iCircularBuffer *buffer)
 * \brief Gets the min of the buffer values.
 *
 * \param buffer A pointer to the buffer object 
 * \return The mean value
 */
int icb_min(iCircularBuffer *buffer);

/**
 * \fn void fcb_min(fCircularBuffer *buffer)
 * \brief Gets the min of the buffer values.
 *
 * \param buffer A pointer to the buffer object 
 * \return The mean value
 */
float fcb_min(fCircularBuffer *buffer);

/**
 * \fn void fcb_argmax(fCircularBuffer *buffer)
 * \brief Gets the argmax of the buffer values.
 *
 * \param buffer A pointer to the buffer object 
 * \return The mean value
 */
int icb_argmax(iCircularBuffer *buffer);

/**
 * \fn void fcb_argmax(fCircularBuffer *buffer)
 * \brief Gets the argmax of the buffer values.
 *
 * \param buffer A pointer to the buffer object 
 * \return The mean value
 */
int fcb_argmax(fCircularBuffer *buffer);



/**
 * \fn void icb_argmin(fCircularBuffer *buffer)
 * \brief Gets the argmin of the buffer values.
 *
 * \param buffer A pointer to the buffer object 
 * \return The mean value
 */
int icb_argmin(iCircularBuffer *buffer);

/**
 * \fn void fcb_argmin(fCircularBuffer *buffer)
 * \brief Gets the argmin of the buffer values.
 *
 * \param buffer A pointer to the buffer object 
 * \return The mean value
 */
int fcb_argmin(fCircularBuffer *buffer);

/**
 * \fn int icb_get_at(iCircularBuffer *buffer, int pos)
 * \brief get value at position pos in the time reference (0 is the oldest value in the buffer)
 *
 * \param buffer A pointer to the buffer object
 * \param pos the discrete time position of the value to be recovered
 * \return the value at the position pos
 */
int icb_get_at(iCircularBuffer *buffer, int pos);
/**
 * \fn float fcb_get_at(fCircularBuffer *buffer, int pos)
 * \brief get value at position pos in the time reference (0 is the oldest value in the buffer)
 *
 * \param buffer A pointer to the buffer object
 * \param pos the discrete time position of the value to be recovered
 * \return the value at the position pos
 */
float fcb_get_at(fCircularBuffer *buffer, int pos);

/**
 * \fn void fcb_straighten(iCircularBuffer *buffer, iCircularBuffer *straightened_buffer)
 * \brief Makes a straightened copy of a buffer. A straightened buffer has the oldest value in position 0 and latest on position head==count.
 *
 * \param buffer A pointer to the buffer object to be straightened
 * \param buffer A pointer to the buffer object to contyain the straightened data
 * \return The mean value
 */
void icb_straightened_copy(iCircularBuffer *buffer, iCircularBuffer *straightened_buffer);

/**
 * \fn void fcb_straighten(fCircularBuffer *buffer, fCircularBuffer *straightened_buffer)
 * \brief Makes a straightened copy of a buffer. A straightened buffer has the oldest value in position 0 and latest on position head==count.
 *
 * \param buffer A pointer to the buffer object to be straightened
 * \param buffer A pointer to the buffer object to contyain the straightened data
 * \return The mean value
 */
void fcb_straightened_copy(fCircularBuffer *buffer, fCircularBuffer *straightened_buffer);

/**
 * \fn fcb_remove_at(fCircularBuffer *buffer, int position
 * \brief Removes a value at a specific position
 *
 * \param buffer A pointer to the buffer object
 * \param index index of the value to be removed
 * \return The mean value
 */
void fcb_remove_at(fCircularBuffer *buffer, int index);



/**
 * \fn icb_remove_at_timeindex(iCircularBuffer *buffer, int position
 * \brief Removes a value at a specific index (please consider straightening the buffer if you want to remove at timed position)
 *
 * \param buffer A pointer to the buffer object
 * \param index index of the value to be removed
 * \return Nothing
 */
void icb_remove_at_timeindex(iCircularBuffer *buffer, int index)<<;

/**
 * \fn fcb_remove_at_timeindex(fCircularBuffer *buffer, int position
 * \brief Removes a value at a specific index (please consider straightening the buffer if you want to remove at timed position)
 *
 * \param buffer A pointer to the buffer object
 * \param index index of the value to be removed
 * \return Nothing
 */
void fcb_remove_at_timeindex(fCircularBuffer *buffer, int index);
#endif
