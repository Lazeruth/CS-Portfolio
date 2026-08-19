## Artemis Financial: Secure Software Practices
**Course:** CS-305 Software Security  
**Project:** Vulnerability Assessment & Application Hardening  

---

### Project Overview
Artemis Financial, a consulting client, required a modernization of their public web interface and operations to protect sensitive client financial data. The primary issue addressed was the need to implement secure communication protocols and a robust data verification step—specifically a cryptographic checksum—to ensure data integrity during transfers. 

### Vulnerability Assessment & Mitigation
Identifying, analyzing, and stripping out vulnerable dependencies using a Software Bill of Materials (SBOM) was a highly successful aspect of this assessment. Navigating deep transitive dependencies to achieve a zero-vulnerability report was the most challenging component, but it provided invaluable, hands-on experience in securing modern software supply chains. 

Coding securely is a critical necessity; it fundamentally protects an organization's operational integrity, reduces legal liability, and safeguards user data against unauthorized access. Software security adds immense value to a company’s overall well-being by maintaining client trust and preventing catastrophic financial loss.

### Security Enhancements & Testing
To increase the layers of security, several critical refactoring steps were executed:

* **Transport-Layer Security:** Replaced unencrypted HTTP endpoints with strict TLS 1.2/1.3 protocols.
* **Cryptographic Upgrades:** Migrated weak, legacy algorithms to AES-256-GCM for symmetric encryption and SHA-256 for secure hashing.
* **Authentication:** Generated and implemented self-signed X.509 certificates using RSA-2048 for secure asymmetric key exchange.

To ensure the software remained functional, automated testing suites and manual endpoint verifications (e.g., testing the secure `/hash` route in the browser) were conducted post-refactoring. To confirm no new vulnerabilities were introduced, secondary static application security testing (SAST) was executed via the OWASP dependency-check tool, confirming zero high- or critical-severity CVEs remained. Future assessments will continue to utilize continuous dependency management, SAST, and Software Composition Analysis (SCA) within the CI/CD pipeline to dictate mitigation techniques.

### Industry Best Practices & Professional Value
Throughout this project, resources like the Java Keytool and Maven dependency scanners were utilized alongside industry best practices like Defense in Depth and the Principle of Least Privilege (PoLP). 

The ability to systematically transform an unencrypted legacy application into a hardened, production-ready system is a premier technical skill to showcase to future employers. Furthermore, the secure architecture methodologies utilized here demonstrate a readiness to design resilient, enterprise-grade data analytics and IT solutions for modern consulting environments like Louava.

---

*Developed by Corey Peterson-Lopez*
