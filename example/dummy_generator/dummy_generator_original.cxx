
template < typename T >
DummyGenerator<T>::DummyGenerator( T inInitialValue, T inDifference )
	: nextValue_( inInitialValue ), difference_( inDifference )
{
}

template < typename T >
T DummyGenerator<T>::next()
{
	T outValue = nextValue_;
	nextValue_ += difference_;
	return outValue;
}

template < typename T >
void DummyGenerator<T>::init(T inNextvalue, T inDifference) {
	 nextValue_ = inNextvalue;
	 difference_ = inDifference;
}

