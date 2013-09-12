#!/usr/bin/env python


for i in xrange(ord('a'), ord('z') + 1):
    print "typedef char_< '%c' > %c_;" % (chr(i), chr(i))
for i in xrange(ord('A'), ord('Z') + 1):
    print "typedef char_< '%c' > %c_;" % (chr(i), chr(i))
print

# in evaluation order
types = [
    "unsigned short", 
    "unsigned long long",
    "unsigned long", 
    "long double",
    "long long", 
    "long", 
    "octet", 
    "char", 
    "short",
    "float", 
    "double", 
    "string",
    "wstring",
    "void",
    ]
tokens = [
    "attribute",
    "oneway",
    "readonly",
    "in",
    "out",
    "inout",
    "struct",
    "module",
    "interface",
    "abstract",
    "typedef",
    "enum",
    "sequence",
    "const",
    "true",
    "false",
    "union",
    "case",
    "switch",
    "default",
    "expcetion",
    "valuetype",
    "factory",
    "setraises",
    "getraises",
    "raises",
    "public",
    "private",
    "fixed",
    ]
tokens.extend(types)

for i in tokens:
    tail = 0
    line = []
    t = i.replace(' ', '_')
    for j in xrange(len(t)):
        if len(line) % 7 == 0 and j != len(t) - 1:
            k = "seq" if tail > 0 else "tok"
            line.append("%s_ < %c_" % (k, t[j]))
            tail += 1
        else:
            line.append("%c_" % t[j])

    print "typedef " + ", ".join(line) + (" >" * tail) + " " + t + "_t;"

print

for i in types:
    t = "PT_" + i.replace(' ', '_').upper() + ","
    print t
print

print "typedef or_<"
ts = []
for i in types:
    t = "PT_" + i.replace(' ', '_').upper()
    line = "primitive_type < " + i.replace(' ', '_') + "_t, " + t + " >"

    ts.append(line)
print "       " + ",\n       ".join(ts)
print "    > primitive_types_rule;"
print



