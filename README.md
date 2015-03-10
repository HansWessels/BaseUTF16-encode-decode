# BaseUTF16-encode-decode


## What is it good for?

Pack as much (structured or stream) data as possible in a JavaScript Unicode (UTF16) string. 

Good for LocalStorage and network transfer. 

Use this encoder to fully utilize the storage space offered by modern JavaScript / browser technology.


## What is this BaseUTF16?

This encoder/decoder encodes an arbitrary datastream or object model to a standard-compliant UTF16 representation suitable for use in JavaScript localStorage and other spots where JavaSctript strings are expected rather than random (binary or object) data.


## Features / The Power of BaseUTF16

BaseUTF16-encode-decode is the `JSON.stringify` and Base*N* alternative which properly utilizes modern hardware and software:

- produces a guaranteed standard-compliant UTF16 output stream, which can be stored or transmitted as a JavaScript string.

- A proprocessor accepts arbitrary JavaScript structures as input, allowing this stream converter to be used as a far more storage-optimal `JSON.stringify` alternative.

- Full, optimal use of the available UTF16 code space: packing more oomph in fewer UTF-16 characters!

- You can freely format the BaseUTF16 Unicode string output using speces, tabs and carriage returns / line feed characters as those are skipped by the decoder.

- Uses a [MessagePack](http://msgpack.org/) derivative to help serialize structured data.

- Cyclic references in structured input data *are supported*!


## Inspiration

Akin to / inspired by Huffman encoding, [MessagePack](http://msgpack.org/) and the Base64, UUEncode and YEncoding 'alphabet mapping' encoding/decoding protocols.

This encoder/decoder uses a *fast* Huffman encoding/decoding algorithm originating from the same data compression technology.

