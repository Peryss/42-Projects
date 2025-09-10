template <typename T> class Array {
	private:
		T*				_data;
		unsigned int	_size;
	public:
		Array ();
		Array (unsigned int n);
		Array operator= (const Array& other);
		Array (const Array&other);
		~Array();
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		unsigned int size() const
};