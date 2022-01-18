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

## Sprite metadata

> Sprite metadata is a chunk of data that's placed just before sprite data

### Components
1) Data length (ranging from **0x00** to **0xFF**)

## Sprite data

> Sprite data is a way of storing graphics and their corresponding colors in few bytes

### Components

1) Pixel color (**0x00** to **0xFE** pixels) (correspond to a palette **index**)
2) EOGL (end of graphic line) -- a **0x00** byte that signal the end of a sprite line

