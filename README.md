# Sprite engine

## Palette

> Sprite palette is a small index containing a maximum of 255 colors
- 1 byte for color number
- 3 byte per color *HEX (R,G,B)*

### Example
> 01 FF FF FF

*Represents a color palette of length 1, containing colors :*
1) White (0xFFFFFF)
> 02 FF FF FF 00 00 00
*Represents a color palette of length 2, containing colors :*
1) White (0xFFFFFF)
2) Black (0x000000)
> 01 FF 00 FF 00 FF 00

*Is an invalid color palette, as the fixed length is set to 1, and it contains two colors.*

**In that case the behavior is undefined**