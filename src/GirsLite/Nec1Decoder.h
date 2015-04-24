#ifndef NEC1DECODER_H
#define	NEC1DECODER_H

#include "Decoder.h"
#include "IrCapturer.h"
#include "IrReceiver.h"

class Nec1Decoder : public Decoder {
private:
    static const unsigned int timebase = 564;
    static const unsigned int timebaseUpper = 650;
    static const unsigned int timebaseLower = 450;
    unsigned int F;
    unsigned int D;
    unsigned int S;
    bool ditto;

public:
    Nec1Decoder();
    //Nec1Decoder(uint16_t* irSequence, unsigned int length);
    Nec1Decoder(const IrCapturer& irCapturer);
    Nec1Decoder(const IrReceiver& irReceiver);
    //Nec1Decoder(const Nec1Decoder& orig);
    //virtual ~Nec1Decoder();

    unsigned int getF() const {
        return F;
    }
    unsigned int getD() const {
        return D;
    }
    unsigned int getS() const {
        return S;
    }
    bool isDitto() const {
        return ditto;
    }
    uint32_t getTimebase() const { return timebase; }
    uint32_t getTimebaseLower() const { return timebaseLower; }
    uint32_t getTimebaseUpper() const { return timebaseUpper; }

    String toString() const;
    unsigned int decodeFlashGap(uint32_t flash, uint32_t gap) const;
    unsigned int decode(const IrCapturer& irCapturer, unsigned int index) const;
    unsigned int decode(const IrReceiver& irCapturer, unsigned int index) const;
};

#endif	/* NEC1DECODER_H */
