/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#ifndef itkPyVnl_h
#define itkPyVnl_h

#include <vnl/vnl_vector.h>
#include <vnl/vnl_matrix.h>

// The python header defines _POSIX_C_SOURCE without a preceding #undef
#undef _POSIX_C_SOURCE
#undef _XOPEN_SOURCE
// For Python 2.7 hypot bug, see https://bugs.python.org/issue11566
#include <Python.h>
//#include "PatchedPython27pyconfig.h"

namespace itk
{

/** \class PyVnl
 *
 *  \brief Helper class get views of VNL data buffers in python arrays and back.
 *
 *  This class will receive a VNL data structure and create the equivalent python
 *  array view. This permits passing VNL data structures into python arrays from
 *  the NumPy python package.
 *
 *  \ingroup BridgeNumPy
 */
template <typename TElement>
class PyVnl
{
public:
  /** Standard "Self" typedef. */
  typedef PyVnl         Self;

  /** Type of the data from which the buffer will be converted */
  typedef TElement                                             DataType;
  typedef vnl_vector<TElement>                                 VectorType;
  typedef vnl_matrix<TElement>                                 MatrixType;

  /**
   * Get an Array with the content of the vnl vector
   */
  static PyObject * _GetArrayViewFromVnlVector( VectorType * vector);

  /**
   * Get a vnl vector from a Python array
   */
  static const VectorType _GetVnlVectorViewFromArray( PyObject *arr, PyObject *shape);

  /**
   * Get an Array with the content of the vnl matrix
   */
  static PyObject * _GetArrayViewFromVnlMatrix( MatrixType * matrix);

  /**
   * Get a vnl matrix from a Python array
   */
  static const MatrixType _GetVnlMatrixViewFromArray( PyObject *arr, PyObject *shape);


protected:

private:
  PyVnl(const Self&);       // Purposely not implemented.
  void operator=(const Self&); // Purposely not implemented.
};

} // namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkPyVnl.hxx"
#endif

#endif // _itkPyVnl_h