s/^(\([EWI]\)) \([A-Z][0-9]*-*[A-Z]*\); "\(.*\)":\([0-9]*\):\([0-9]*\): \(.*\)/\3(\4) : (\1) \2 : \6/
s/error/Error/g
s/warning/Warning/g
s/notice/Informational/g
s/..\\..\\..\\cu\\//
s/..\\..\\../../