#ifndef VECTOR_H
#define VECTOR_H

using namespace std;

    /**
	 * @class Vector
	 * @brief  This class create template dynamic array that provides
	 *          the program flexibility to work with large files and huge data.
	 *
	 * @author Sin Loo Mah
	 * @version 01
	 * @date 22/4/2019
	 *
	 * @bug My program has no bugs. Well, maybe it has...
	 */


template <class T>
class Vector
{
    public:

        /**
        * @brief default constructor

        * @return void
        */
        Vector();

        Vector(const Vector <T>& VV);

        /**
        * @brief default constructor
        *
        * @return void
        */
        void addObj(const T& obj);

        /**
        * @brief keeps track of the index
        *
        * @return void
        */
        const T& getIndex(unsigned int aindex) const;

        /**
        * @brief returns the value stored at the specified index.
        *
        * @return void unsigned int
        */
        unsigned int getCurrentIndex() const;

        /**
        * @brief keeps track of the size at a given instance.
        *
        * @return unsigned int size
        */
        unsigned int getCurrentSize() const;

        /**
        * @brief destructor for Vector.
        *
        * @return void
        */
        ~Vector();

        /**
        * @brief this is used for copying between vectors
        *
        * @return Vector<T>
        */
        Vector<T>& operator = (const Vector <T>& VV);

        /**
        * @brief this is used to re size the array
        *
        * @return void
        */
        void ResizeArray();


    private:

        /// pointer array of the stored elements
        T* VArray;

        /// index gives the current index at runtime
        unsigned int index;

        /// current array size
        unsigned int arraySize;

};


template <class T>
Vector<T>::Vector()
{
    arraySize = 10;
    VArray = new T[arraySize];
    index = 0;

}

template <class T>
void Vector<T>::addObj(const T& obj)
{
    if(index == arraySize){
        ResizeArray();
    }
    VArray[index] = obj;
    index++;
}

template <class T>
Vector<T>::~Vector(){
    delete[] VArray;
}

template <class T>
void Vector<T>::ResizeArray()
{
    arraySize = arraySize * 2;

    T* tempArray = new T[arraySize];

    for(unsigned int i=0;i<index;i++)
    {
        tempArray[i] = VArray[i];
    }

    delete[] VArray;

    VArray = new T[arraySize];

    for(unsigned int i = 0; i<index; i++)
    {
        VArray[i] = tempArray[i];
    }

    delete [] tempArray;

}

template <class T>
unsigned int Vector<T>::getCurrentIndex() const
{
    return index;
}

template <class T>
unsigned int Vector<T>::getCurrentSize() const
{
    return arraySize;
}

template <class T>
const T& Vector<T>::getIndex(unsigned int aindex) const
{
    return VArray[aindex];
}

template <class T>
Vector <T>& Vector<T>::operator = (const Vector <T>& VV)
{
    delete[] VArray;

    arraySize = VV.getCurrentSize();

    VArray = new T[arraySize];

    index = VV.getCurrentIndex();

    for(unsigned i = 0; i < VV.getCurrentIndex(); i++)
    {
        VArray[i] = VV.getIndex(i);
    }
}

#endif // VECTOR_H


