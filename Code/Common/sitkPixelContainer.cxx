#include "sitkPixelContainer.h"
#include "sitkPixelContainer.txx"

namespace itk
{
  namespace simple
  {

    PixelContainer::PixelContainer()
    {
      this->m_Internal = NULL;
    }

    PixelContainer::~PixelContainer()
    {
      // no need to check if null
      delete this->m_Internal;
      this->m_Internal = NULL;
    }

    PixelIDValueType PixelContainer::GetPixelIDValue( void ) const
    {
      assert( m_Internal );
      return this->m_Internal->GetPixelIDValue();
    }

    std::string PixelContainer::GetPixelIDTypeAsString( void ) const
    {
      return std::string( GetPixelIDValueAsString( this->GetPixelIDValue() ) );
    }

    std::string PixelContainer::ToString( void )
    {
      assert( m_Internal );
      return this->m_Internal->ToString();
    }

    uint64_t PixelContainer::GetNumberOfPixels( void ) const
    {
      assert( m_Internal );
      return this->m_Internal->GetNumberOfPixels();
    }

    int8_t * PixelContainer::GetBufferAsInt8()
    {
      assert( m_Internal );
      return this->m_Internal->GetBufferAsInt8();
    }

    void PixelContainer::SetBufferAsInt8( int8_t * buffer, uint64_t numberOfElements )
    {
      assert( m_Internal );
      return this->m_Internal->SetBufferAsInt8( buffer, numberOfElements );
    }

    uint8_t * PixelContainer::GetBufferAsUnsignedInt8()
    {
      assert( m_Internal );
      return this->m_Internal->GetBufferAsUnsignedInt8();
    }

    void PixelContainer::SetBufferAsUnsignedInt8(  uint8_t * buffer, uint64_t numberOfElements )
    {
      assert( m_Internal );
      return this->m_Internal->SetBufferAsUnsignedInt8( buffer, numberOfElements );
    }

    int16_t * PixelContainer::GetBufferAsInt16()
    {
      assert( m_Internal );
      return this->m_Internal->GetBufferAsInt16();
    }

    void PixelContainer::SetBufferAsInt16( int16_t * buffer, uint64_t numberOfElements )
    {
      assert( m_Internal );
      return this->m_Internal->SetBufferAsInt16( buffer, numberOfElements );
    }

    uint16_t * PixelContainer::GetBufferAsUnsignedInt16()
    {
      assert( m_Internal );
      return this->m_Internal->GetBufferAsUnsignedInt16();
    }

    void PixelContainer::SetBufferAsUnsignedInt16( uint16_t * buffer, uint64_t numberOfElements )
    {
      assert( m_Internal );
      return this->m_Internal->SetBufferAsUnsignedInt16( buffer, numberOfElements );
    }

    int32_t * PixelContainer::GetBufferAsInt32()
    {
      assert( m_Internal );
      return this->m_Internal->GetBufferAsInt32();
    }

    void PixelContainer::SetBufferAsInt32(  int32_t * buffer, uint64_t numberOfElements )
    {
      assert( m_Internal );
      return this->m_Internal->SetBufferAsInt32( buffer, numberOfElements );
    }

    uint32_t * PixelContainer::GetBufferAsUnsignedInt32()
    {
      assert( m_Internal );
      return this->m_Internal->GetBufferAsUnsignedInt32();
    }

    void PixelContainer::SetBufferAsUnsignedInt32(  uint32_t * buffer, uint64_t numberOfElements )
    {
      assert( m_Internal );
      return this->m_Internal->SetBufferAsUnsignedInt32( buffer, numberOfElements );
    }

    float * PixelContainer::GetBufferAsFloat()
    {
      assert( m_Internal );
      return this->m_Internal->GetBufferAsFloat();
    }

    void PixelContainer::SetBufferAsFloat(float * buffer, uint64_t numberOfElements )
    {
      assert( m_Internal );
      return this->m_Internal->SetBufferAsFloat( buffer, numberOfElements );
    }

    double * PixelContainer::GetBufferAsDouble()
    {
      assert( m_Internal );
      return this->m_Internal->GetBufferAsDouble();
    }

    void PixelContainer::SetBufferAsDouble(  double * buffer, uint64_t numberOfElements )
    {
      assert( m_Internal );
      return this->m_Internal->SetBufferAsDouble( buffer, numberOfElements );
    }

  }
}
