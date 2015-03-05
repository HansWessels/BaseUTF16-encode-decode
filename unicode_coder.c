int make_tables(int32 *ranges, int *clen, int* encode_tab, int* decode_tab)
  /*
  ** ranges: pairs of 16 bit integers, first is start, second the end of the range, -1 end of table.
  **
  ** int clen[65536]: length of the codes, to be filled by this routine
  **
  ** int endcode_tab[65536]: table used for the encoder, to be filled by this routine
  **
  ** int decode_tab[65536]: table used for the decoder, to be filled by this routine
  **
  */
  { /* init arrays */
    int i;
    for(i=0; i<65536; i++)
    {
      clen[i]=0;
      endcode_tab[i]=0;
      decode_tab[i]=0;
    }
  }
  { /* determine ranges */
    int start;
    int end;
    start=*ranges++;
    end=*ranges++;
    while(start!=-1)
    {
      while(start<=end)
      {
        clen[start]=1;
        start++;
      }
      start=*ranges++;
      end=*ranges++;
    }
  }
  { /* count number of characters */
    int i;
    int n;
    int code;
    n=0;
    for(i=0; i<65536; i++)
    {
      n+=clen[i];
    }
    if(n<32768)
    { /* we want more than 32767 entries */
      return -1;
    }
    /* we start with 16 bit codes */
    code=0;
    i=0;
    // at exactly n=32K each entry would get two 15-bit code slots,
    // thus filling the 64K lookup space.
    // Every extra entry above 32K requires the 15-bit range to be 
    // reduced by one slot to allow the huffman tree to map to this
    // 16-bit entry instead.
    //
    // --- 
    //
    // Original Hans' explanation (much clearer):
    //
    // - we have a 16 bit range to fill: 2^16 codes
    // - we have N characters to map
    // - we have A 15-bit codes
    // - we have B 16-bit codes
    // The above two statements imply these statements are valid:
    // A + B = N
    // 2A + B = 2^16
    // solving these two equations results in the expression:
    // B = 2N - 2^16
    // A = 2^16 - N
    n=2*n-65536;			// now n = B
    while(code<n)
    {
      if(clen[i])
      {
        clen[i]=16;
        decode_tab[i]=code;
        encode_tab[code]=i;
        code++;
      }
      i++;
    }
    /* finish with the 15 bit codes */
    while(i<65536)
    {
      if(clen[i])
      {
        clen[i]=15;
        decode_tab[i]=(code>>1);
        // the bits to map (encode) are in the MSB; the lowest extra bit
        // doesn't matter: we wish to perform a fast lookup so we always
        // test the lookup table with 16 bits; the LSBit may be (or may NOT be)
        // part of the actual code we're looking for right here.
        encode_tab[code]=i;
        code++;
        encode_tab[code]=i;
        code++;
      }
      i++;
    }
  }
  return 0;
}