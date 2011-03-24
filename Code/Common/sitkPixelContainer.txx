#ifndef __sitkPixelContainer_txx
#define __sitkPixelContainer_txx

#include "sitkPixelContainer.h"
#include "itkImage.h"
#include "itkVectorImage.h"
#include "itkLabelMap.h"
#include "itkLabelObject.h"

namespace itk
{
  namespace simple
  {

  /** \class PimplePixelContainerBase
   * \brief Base class of private implementation idom pixel container
   * class
   */
  class PimplePixelContainerBase
  {
  public:

    PimplePixelContainerBase() {}
    virtual ~PimplePixelContainerBase() {}

    virtual uint64_t GetNumberOfPixels( void ) const = 0;

    virtual PixelIDValueType GetPixelIDValue( void ) const = 0;
    virtual std::string ToString( void ) const = 0;

    virtual int8_t    * GetBufferAsInt8() = 0;
    virtual uint8_t   * GetBufferAsUnsignedInt8() = 0;
    virtual int16_t   * GetBufferAsInt16() = 0;
    virtual uint16_t  * GetBufferAsUnsignedInt16() = 0;
    virtual int32_t   * GetBufferAsInt32() = 0;
    virtual uint32_t  * GetBufferAsUnsignedInt32() = 0;
    virtual float     * GetBufferAsFloat() = 0;
    virtual double    * GetBufferAsDouble() = 0;

    virtual void SetBufferAsInt8( int8_t *, uint64_t numberOfElements ) = 0;
    virtual void SetBufferAsUnsignedInt8( uint8_t *, uint64_t numberOfElements ) = 0;
    virtual void SetBufferAsInt16( int16_t *, uint64_t numberOfElements ) = 0;
    virtual void SetBufferAsUnsignedInt16( uint16_t *, uint64_t numberOfElements ) = 0;
    virtual void SetBufferAsInt32( int32_t *, uint64_t numberOfElements ) = 0;
    virtual void SetBufferAsUnsignedInt32( uint32_t *, uint64_t numberOfElements ) = 0;
    virtual void SetBufferAsFloat( float *, uint64_t numberOfElements ) = 0;
    virtual void SetBufferAsDouble( double *, uint64_t numberOfElements ) = 0;
  };

  ///
  /// Private name space for a concrete implementation of pimple
  /// PixelContainer for a specific image types with dimensions and
  /// pixel types
  ///
  namespace
  {

  /** \class PimplePixelContainer
   * \brief Private implementation idom pixel container class
   */
  template <class TImageType>
  class PimplePixelContainer
    : public PimplePixelContainerBase
  {
  public:
    typedef typename TImageType::PixelContainer  PixelContainerType;
    typedef typename PixelContainerType::Pointer PixelContainerPointer;

    PimplePixelContainer( TImageType * image )
      {
      this->m_PixelContainer = image->GetPixelContainer();
      }

    PixelContainerType * GetPixelContainer()
      {
      return this->m_PixelContainer.GetPointer();
      }

    PixelIDValueType GetPixelIDValue( void ) const
      {
      return ImageTypeToPixelIDValue< TImageType >::Result;
      }

    std::string ToString( void ) const
      {
      std::ostringstream out;
      this->m_PixelContainer->Print( out );
      return out.str();
      }

    uint64_t GetNumberOfPixels( void ) const
    {
      return static_cast< uint64_t >( this->m_PixelContainer->Size() );
    }

    int8_t * GetBufferAsInt8()
    {
      int8_t * buffer = reinterpret_cast< int8_t * >(
        this->m_PixelContainer->GetImportPointer() );
      return buffer;
    }

    void SetBufferAsInt8( int8_t * buffer, uint64_t numberOfElements )
    {
      typedef typename PixelContainerType::Element ElementType;
      ElementType * pixelBuffer = reinterpret_cast< ElementType * >( buffer );
      this->m_PixelContainer->SetImportPointer( pixelBuffer, numberOfElements, false );
    }

    uint8_t * GetBufferAsUnsignedInt8()
    {
      uint8_t * buffer = reinterpret_cast< uint8_t * >(
        this->m_PixelContainer->GetImportPointer() );
      return buffer;
    }

    void SetBufferAsUnsignedInt8( uint8_t * buffer, uint64_t numberOfElements )
    {
      typedef typename PixelContainerType::Element ElementType;
      ElementType * pixelBuffer = reinterpret_cast< ElementType * >( buffer );
      this->m_PixelContainer->SetImportPointer( pixelBuffer, numberOfElements, false );
    }

    int16_t * GetBufferAsInt16()
    {
      int16_t * buffer = reinterpret_cast< int16_t * >(
        this->m_PixelContainer->GetImportPointer() );
      return buffer;
    }

    void SetBufferAsInt16( int16_t * buffer, uint64_t numberOfElements )
    {
      typedef typename PixelContainerType::Element ElementType;
      ElementType * pixelBuffer = reinterpret_cast< ElementType * >( buffer );
      this->m_PixelContainer->SetImportPointer( pixelBuffer, numberOfElements, false );
    }

    uint16_t * GetBufferAsUnsignedInt16()
    {
      uint16_t * buffer = reinterpret_cast< uint16_t * >(
        this->m_PixelContainer->GetImportPointer() );
      return buffer;
    }

    void SetBufferAsUnsignedInt16( uint16_t * buffer, uint64_t numberOfElements )
    {
      typedef typename PixelContainerType::Element ElementType;
      ElementType * pixelBuffer = reinterpret_cast< ElementType * >( buffer );
      this->m_PixelContainer->SetImportPointer( pixelBuffer, numberOfElements, false );
    }

    int32_t * GetBufferAsInt32()
    {
      int32_t * buffer = reinterpret_cast< int32_t * >(
        this->m_PixelContainer->GetImportPointer() );
      return buffer;
    }

    void SetBufferAsInt32( int32_t * buffer, uint64_t numberOfElements )
    {
      typedef typename PixelContainerType::Element ElementType;
      ElementType * pixelBuffer = reinterpret_cast< ElementType * >( buffer );
      this->m_PixelContainer->SetImportPointer( pixelBuffer, numberOfElements, false );
    }

    uint32_t * GetBufferAsUnsignedInt32()
    {
      uint32_t * buffer = reinterpret_cast< uint32_t * >(
        this->m_PixelContainer->GetImportPointer() );
      return buffer;
    }

    void SetBufferAsUnsignedInt32( uint32_t * buffer, uint64_t numberOfElements )
    {
      typedef typename PixelContainerType::Element ElementType;
      ElementType * pixelBuffer = reinterpret_cast< ElementType * >( buffer );
      this->m_PixelContainer->SetImportPointer( pixelBuffer, numberOfElements, false );
    }

    float * GetBufferAsFloat()
    {
      float * buffer = reinterpret_cast< float * >(
        this->m_PixelContainer->GetImportPointer() );
      return buffer;
    }

    void SetBufferAsFloat( float * buffer, uint64_t numberOfElements )
    {
      typedef typename PixelContainerType::Element ElementType;
      ElementType * pixelBuffer = reinterpret_cast< ElementType * >( buffer );
      this->m_PixelContainer->SetImportPointer( pixelBuffer, numberOfElements, false );
    }

    double * GetBufferAsDouble()
    {
      double * buffer = reinterpret_cast< double * >(
        this->m_PixelContainer->GetImportPointer() );
      return buffer;
    }

    void SetBufferAsDouble( double * buffer, uint64_t numberOfElements )
    {
      typedef typename PixelContainerType::Element ElementType;
      ElementType * pixelBuffer = reinterpret_cast< ElementType * >( buffer );
      this->m_PixelContainer->SetImportPointer( pixelBuffer, numberOfElements, false );
    }




  private:
    PixelContainerPointer   m_PixelContainer;
  };

  }
  //
  // End private namespace for pimple implementation
  //

  template <typename TImageType>
  void PixelContainer::InternalInitialization( TImageType * image )
  {
    typedef PimplePixelContainer< TImageType >  PixelContainerType;

    delete this->m_Internal;
    this->m_Internal = new PixelContainerType( image );
  }

  }
}


#endif
