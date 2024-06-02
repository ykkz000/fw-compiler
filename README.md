# FW-Compiler
## Compile
Use `cmake` and `make`.
## Usage
```sh
fwc <source file>
```
## Lauguage
Base on XML
The document should be like this
```xml
<root>
    <rule>
        <saddr>127.0.0.1</saddr>
        <daddr>127.0.0.2</daddr>
        <sport>225</sport>
        <dport>236</dport>
        <NLProtocol>IP</NLProtocol>
        <TLProtocol>TCP</TLProtocol>
    </rule>
    <rule>
        <saddr>127.0.0.1</saddr>
        <daddr>127.0.0.2</daddr>
        <NLProtocol>IP</NLProtocol>
        <TLProtocol>ICMP</TLProtocol>
    </rule>
</root>
```
### Supported Network Layer Protocol
IP, ARP and RARP
### Supported Transiport Layer Protocol
TCP, UDP and ICMP
## Notice
IPv6 is not supported!!!