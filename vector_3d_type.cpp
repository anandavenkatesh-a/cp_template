/// A simple, sensible, general 3D vector
///
/// In-place methods have been suffixed with `_ip`, but they really shouldn't
/// need to be used all that much. These methods are simple, so intermediate
/// vector copies will almost assuredly be optimized out.
class Vec3D {
    using real = ld;
public:
    /// Components
    real x, y, z;

    /// Construct all components to zero
    Vec3D() = default;

    /// Construct all components to single value
    explicit Vec3D(const real c) : x(c), y(c), z(c) {}

    /// Construct from individual components
    Vec3D(const real i, const real j, const real k) : x(i), y(j), z(k) {}

    /// Zero out all components
    void set_zero() {
        x = y = z = 0;
    }

    /// Length (Euclidean norm)
    real length() const {
        return std::sqrt(length_squared());
    }

    /// Length squared (vector dotted with itself)
    real length_squared() const {
        return dot(*this);
    }

    /// Reverse
    Vec3D operator-() const {
        return Vec3D(-x, -y, -z);
    }

    /// Reverse in-place
    Vec3D& reverse_ip() {
        return *this = -*this;
    }

    /// Normalized
    Vec3D normalized() const {
        return *this / length();
    }

    /// Normalize in-place
    void normalize_ip() {
        *this /= length();
    }

    /// Addition
    Vec3D operator+(const Vec3D& rhs) const {
        return Vec3D(x + rhs.x, y + rhs.y, z + rhs.z);
    }

    /// Addition assignment
    Vec3D& operator+=(const Vec3D& rhs) {
        return *this = *this + rhs;
    }

    /// Subtraction
    Vec3D operator-(const Vec3D& rhs) const {
        return Vec3D(x - rhs.x, y - rhs.y, z - rhs.z);
    }

    /// Subtraction assignment
    Vec3D& operator-=(const Vec3D& rhs) {
        return *this = *this - rhs;
    }

    /// Scalar multiplication
    Vec3D operator*(const real c) const {
        return Vec3D(x * c, y * c, z * c);
    }
  
    /// Commutative scalar multiplication
    friend Vec3D operator*(const real c, const Vec3D& vec) {
        return vec * c;
    }

    /// Scalar multiplication assignment
    Vec3D& operator*=(const real c) {
        return *this = *this * c;
    }

    /// Scalar division
    Vec3D operator/(const real c) const {
        return *this * (1 / c);
    }

    /// Scalar division assignment
    Vec3D& operator/=(const real c) {
        return *this *= 1 / c;
    }

    /// Dot product
    real dot(const Vec3D& rhs) const {
        return x * rhs.x + y * rhs.y + z * rhs.z;
    }

    /// Cross product
    Vec3D cross(const Vec3D& rhs) const {
        return Vec3D(
            y * rhs.z - z * rhs.y,
            z * rhs.x - x * rhs.z,
            x * rhs.y - y * rhs.x
        );
    }

    /// Cross product in-place
    void cross_ip(const Vec3D& rhs) {
        *this = cross(rhs);
    }

    /// Element-wise multiplication
    Vec3D elem_mult(const Vec3D& rhs) const {
        // I didn't overload `operator*(Vec3D&, Vec3D&)` because I didn't
        // feel it was common enough to warrant the implicitness.
        return Vec3D(x * rhs.x, y * rhs.y, z * rhs.z);
    }

    /// Element-wise multiplication in-place
    void elem_mult_ip(const Vec3D& rhs) {
        *this = elem_mult(rhs);
    }

    /// Distance to
    real dist_to(const Vec3D& to) const {
        return (to - *this).length();
    }

    /// Distance to squared
    real dist_to_squared(const Vec3D& to) const {
        return (to - *this).length_squared();
    }

    /// Projected onto another vector
    Vec3D projected_onto(const Vec3D& onto) const {
        return onto * dot(onto) / onto.length_squared();
    }

    /// Project onto another vector in-place
    void project_onto_ip(const Vec3D& onto) {
        *this = projected_onto(onto);
    }

    /// Equality
    bool operator==(const Vec3D& rhs) const {
        return x == rhs.x &&
               y == rhs.y &&
               z == rhs.z;
    }

    /// Inequality
    bool operator!=(const Vec3D& rhs) const {
        return !(rhs == *this);
    }

    /// Stream debug output
    friend std::ostream& operator<<(std::ostream& os, const Vec3D& d) {
        os << "Vec3D { x: "
           << d.x << ", y: "
           << d.y << ", z: "
           << d.z << " }";
        return os;
    }
};
