# BaseUTF16-encode-decode

The `JSON.stringify` and Base*N* alternative which properly utilizes modern hardware and software:

- produces a guaranteed standard-compliant UTF16 output stream, which can be stored or transmitted as a JavaScript string.

- A proprocessor accepts arbitrary JavaScript structures as input, allowing this stream converter to be used as a far more storage-optimal `JSON.stringify` alternative.

- Full, optimal use of the available UTF16 code space: packing more oomph in fewer UTF-16 characters!


This encoder/decoder encodes an arbitrary datastream or object model to a standard-compliant UTF16 representation suitable for use in JavaScript localStorage and other spots where JavaSctript strings are expected rather than random (binary or object) data. Use this encoder to fully utilize the storage space offered by modern JavaScript / browser technology.

