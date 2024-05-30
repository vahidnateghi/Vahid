namespace Helper
{
    namespace Functions
    {
        inline std::list<std::string>  split( std::string &str, const char delim = ' ' )
        {
            std::list<std::string> result;
            size_t                 start = 0;

            while ( start < str.length() )
            {
                size_t pos = str.find( delim, start );

                if ( pos == std::string::npos ) { pos = str.length(); }

                result.push_back( str.substr( start, pos - start ) );
                start = pos + 1;
            }

            return result;
        }

        template<typename T>
        inline list<T> string2List( std::string &str, const char delim = ',' )
        {
            list<string> strs = Helper::Functions::split( str, delim );
            list<T>      vals;
            std::for_each( strs.begin(), strs.end(), [&vals] ( string &str )
            {
                vals.push_back( (T)std::stoi( str ) );
            } );
            return vals;
        }

        inline list<string> string2List( std::string &str, const char delim = ',' )
        {
            list<string> strs = Helper::Functions::split( str, delim );
            list<string> vals;
            std::for_each( strs.begin(), strs.end(), [&vals] ( string &str )
            {
                vals.push_back( str );
            } );
            return vals;
        }

        template<typename T, size_t N>
        inline array<T, N> string2Array( std::string &str, const char delim = ',' )
        {
            list<string> strs = Helper::Functions::split( str, delim );
            array<T, N>  ret;
            list<T>      vals;
            int          k = 0;
            std::for_each( strs.begin(), strs.end(), [&vals, &ret, &k] ( string &str )
            {
                if( k< N )
                    ret[k++] = (T)std::stoll( str );

            } );
            return ret;
        }

        template<typename T>
        inline string list2String( list<T> vals, const char delim = ',' )
        {
            string ret;

            std::for_each( vals.begin(), vals.end(), [&ret, delim] ( T val )
            {
                ret += ( std::to_string( val )  + delim );
            } );
            ret.resize( ret.size() - 1 );

            return ret;
        }

        inline string list2String( list<string> vals, const char delim = ',' )
        {
            string ret;

            std::for_each( vals.begin(), vals.end(), [&ret, delim] ( string& val )
            {
                ret += ( val  + ( delim ) );
            } );
            ret.resize( ret.size() - 1 );

            return ret;
        }

        template<typename T, size_t N>
        inline string array2String( const array<T, N> &vals, const char delim = ',' )
        {
            string ret;

            std::for_each( vals.begin(), vals.end(), [&ret, delim] ( T val )
            {
                ret += ( std::to_string( val )  + delim );
            } );
            ret.resize( ret.size() - 1 );

            return ret;
        }

        template<typename T>
        inline uint32_t  fromBuf_uint32_BigEnd( T &bufItr )
        {
            uint32_t ret = 0;
            int      i   = 0;

            std::for_each_n( bufItr, 4, [&ret, &i] ( const uint8_t& val )
            {
                uint32_t tval = val * ( pow( 256, i++ ) );
                ret          += tval;

                // ret *= 256;
                // ret += val;
            } );

            return ret;
        }

        template<typename T>
        inline uint32_t  fromBuf_uint32_LitEnd( T &bufItr )
        {
            uint32_t ret = 0;
            int      i   = 0;

            std::for_each_n( bufItr, 4, [&ret, &i] ( const uint8_t& val )
            {
                ret *= 256;
                ret += val;
            } );

            return ret;
        }

        template<typename T>
        inline uint32_t  fromBuf_uint24_BigEnd( T &bufItr )
        {
            uint32_t ret = 0;
            int      i   = 0;

            std::for_each_n( bufItr, 3, [&ret, &i] ( const uint8_t& val )
            {
                uint32_t tval = val * ( pow( 256, i++ ) );
                ret          += tval;

                // ret *= 256;
                // ret += val;
            } );

            return ret;
        }

        template<typename T>
        inline uint32_t  fromBuf_uint24_LitEnd( T &bufItr )
        {
            uint32_t ret = 0;
            int      i   = 0;

            std::for_each_n( bufItr, 3, [&ret, &i] ( const uint8_t& val )
            {
                ret *= 256;
                ret += val;
            } );

            return ret;
        }

        template<typename T>
        inline uint16_t  fromBuf_uint16_BigEnd( T &bufItr )
        {
            uint16_t ret = 0;
            int      i   = 0;

            std::for_each_n( bufItr, 2, [&ret, &i] ( const uint8_t& val )
            {
                uint32_t tval = val * ( pow( 256, i++ ) );
                ret          += tval;

                // ret *= 256;
                // ret += val;
            } );

            return ret;
        }

        template<typename T>
        inline uint16_t  fromBuf_uint16_LitEnd( T &bufItr )
        {
            uint16_t ret = 0;
            int      i   = 0;

            std::for_each_n( bufItr, 2, [&ret, &i] ( const uint8_t& val )
            {
                ret *= 256;
                ret += val;
            } );

            return ret;
        }

        template<typename T>
        inline uint64_t  fromBuf_uint48_BigEnd( T &bufItr )
        {
            uint64_t ret = 0;
            int      i   = 0;

            std::for_each_n( bufItr, 6, [&ret, &i] ( const uint8_t& val )
            {
                uint32_t tval = val * ( pow( 256, i++ ) );
                ret          += tval;

                // ret *= 256;
                // ret += val;
            } );

            return ret;
        }

        template<typename T>
        inline uint64_t  fromBuf_uint48_LitEnd( T &bufItr )
        {
            uint64_t ret = 0;
            int      i   = 0;

            std::for_each_n( bufItr, 6, [&ret, &i] ( const uint8_t& val )
            {
                ret *= 256;
                ret += val;
            } );

            return ret;
        }

        template<typename T>
        inline uint64_t  fromBuf_uint64_BigEnd( T &bufItr )
        {
            uint64_t ret = 0;
            int      i   = 0;

            std::for_each_n( bufItr, 8, [&ret, &i] ( const uint8_t& val )
            {
                uint32_t tval = val * ( pow( 256, i++ ) );
                ret          += tval;

                // ret *= 256;
                // ret += val;
            } );

            return ret;
        }

        template<typename T>
        inline uint64_t  fromBuf_uint64_LitEnd( T &bufItr )
        {
            uint64_t ret = 0;
            int      i   = 0;

            std::for_each_n( bufItr, 8, [&ret, &i] ( const uint8_t& val )
            {
                ret *= 256;
                ret += val;
            } );

            return ret;
        }

        inline std::string  getLocaltime()
        {
            char        buffer[80];
            std::time_t now = std::time( nullptr );

            std::strftime( buffer, 80, "%Y-%m-%d-%H:%M:%S", localtime( &now ) );
            std::string result( buffer );

            return result;
        }

        template<typename T, typename TT>
        inline void  toBuf_uint8( T &buf, TT data )
        {
            uint8_t b0 = data & 0xff;

            buf.push_back( b0 );
        }

        template<typename T, typename TT>
        inline void  toBuf_uint16_BigEnd( T &buf, TT data )
        {
            uint8_t b0 = data & 0xff;
            uint8_t b1 = ( data / 256 ) & 0xff;

            buf.push_back( b1 );
            buf.push_back( b0 );
        }

        template<typename T, typename TT>
        inline void  toBuf_uint16_LitEnd( T &buf, TT data )
        {
            uint8_t b0 = data & 0xff;
            uint8_t b1 = ( data / 256 ) & 0xff;

            buf.push_back( b0 );
            buf.push_back( b1 );
        }

        template<typename T, typename TT>
        inline void  toBuf_uint24_BigEnd( T &buf, TT data )
        {
            uint8_t b0 = data & 0xff;
            uint8_t b1 = ( data / 256 ) & 0xff;
            uint8_t b2 = ( data / ( 256 * 256 ) ) & 0xff;

            buf.push_back( b2 );
            buf.push_back( b1 );
            buf.push_back( b0 );
        }

        template<typename T, typename TT>
        inline void  toBuf_uint24_LitEnd( T &buf, TT data )
        {
            uint8_t b0 = data & 0xff;
            uint8_t b1 = ( data / 256 ) & 0xff;
            uint8_t b2 = ( data / ( 256 * 256 ) ) & 0xff;

            buf.push_back( b0 );
            buf.push_back( b1 );
            buf.push_back( b2 );
        }

        template<typename T, typename TT>
        inline void  toBuf_uint32_BigEnd( T &buf, TT data )
        {
            uint8_t b0 = data & 0xff;
            uint8_t b1 = ( data / 256 ) & 0xff;
            uint8_t b2 = ( data / ( 256 * 256 ) ) & 0xff;
            uint8_t b3 = ( data / ( 256 * 256 * 256 ) ) & 0xff;

            buf.push_back( b3 );
            buf.push_back( b2 );
            buf.push_back( b1 );
            buf.push_back( b0 );
        }

        template<typename T, typename TT>
        inline void  toBuf_uint32_LitEnd( T &buf, TT data )
        {
            uint8_t b0 = data & 0xff;
            uint8_t b1 = ( data / 256 ) & 0xff;
            uint8_t b2 = ( data / ( 256 * 256 ) ) & 0xff;
            uint8_t b3 = ( data / ( 256 * 256 * 256 ) ) & 0xff;

            buf.push_back( b0 );
            buf.push_back( b1 );
            buf.push_back( b2 );
            buf.push_back( b3 );
        }

        template<typename T, typename TT>
        inline void  toBuf_uint64_BigEnd( T &buf, TT data )
        {
            uint8_t b0 = data & 0xff;
            uint8_t b1 = ( data / 256 ) & 0xff;
            uint8_t b2 = ( data / ( 256 * 256 ) ) & 0xff;
            uint8_t b3 = ( data / ( 256 ^ 3 ) ) & 0xff;
            uint8_t b4 = ( data / ( 256 ^ 4 ) ) & 0xff;
            uint8_t b5 = ( data / ( 256 ^ 5 ) ) & 0xff;
            uint8_t b6 = ( data / ( 256 ^ 6 ) ) & 0xff;
            uint8_t b7 = ( data / ( 256 ^ 7 ) ) & 0xff;

            buf.push_back( b7 );
            buf.push_back( b6 );
            buf.push_back( b5 );
            buf.push_back( b4 );
            buf.push_back( b3 );
            buf.push_back( b2 );
            buf.push_back( b1 );
            buf.push_back( b0 );
        }

        template<typename T, typename TT>
        inline void  toBuf_uint64_LitEnd( T &buf, TT data )
        {
            uint8_t b0 = data & 0xff;
            uint8_t b1 = ( data / 256 ) & 0xff;
            uint8_t b2 = ( data / ( 256 * 256 ) ) & 0xff;
            uint8_t b3 = ( data / ( 256 ^ 3 ) ) & 0xff;
            uint8_t b4 = ( data / ( 256 ^ 4 ) ) & 0xff;
            uint8_t b5 = ( data / ( 256 ^ 5 ) ) & 0xff;
            uint8_t b6 = ( data / ( 256 ^ 6 ) ) & 0xff;
            uint8_t b7 = ( data / ( 256 ^ 7 ) ) & 0xff;

            buf.push_back( b0 );
            buf.push_back( b1 );
            buf.push_back( b3 );
            buf.push_back( b4 );
            buf.push_back( b5 );
            buf.push_back( b6 );
            buf.push_back( b2 );
            buf.push_back( b7 );
        }

        template<typename T, typename TT>
        inline void  toBuf_uint48_BigEnd( T &buf, TT data )
        {
            uint8_t b0 = data & 0xff;
            uint8_t b1 = ( data / 256 ) & 0xff;
            uint8_t b2 = ( data / ( 256 * 256 ) ) & 0xff;
            uint8_t b3 = ( data / ( 256 ^ 3 ) ) & 0xff;
            uint8_t b4 = ( data / ( 256 ^ 4 ) ) & 0xff;
            uint8_t b5 = ( data / ( 256 ^ 5 ) ) & 0xff;
            uint8_t b6 = ( data / ( 256 ^ 6 ) ) & 0xff;
            uint8_t b7 = ( data / ( 256 ^ 7 ) ) & 0xff;

            buf.push_back( b5 );
            buf.push_back( b4 );
            buf.push_back( b3 );
            buf.push_back( b2 );
            buf.push_back( b1 );
            buf.push_back( b0 );
        }

        template<typename T, typename TT>
        inline void  toBuf_uint48_LitEnd( T &buf, TT data )
        {
            uint8_t b0 = data & 0xff;
            uint8_t b1 = ( data / 256 ) & 0xff;
            uint8_t b2 = ( data / ( 256 * 256 ) ) & 0xff;
            uint8_t b3 = ( data / ( 256 ^ 3 ) ) & 0xff;
            uint8_t b4 = ( data / ( 256 ^ 4 ) ) & 0xff;
            uint8_t b5 = ( data / ( 256 ^ 5 ) ) & 0xff;
            uint8_t b6 = ( data / ( 256 ^ 6 ) ) & 0xff;
            uint8_t b7 = ( data / ( 256 ^ 7 ) ) & 0xff;

            buf.push_back( b0 );
            buf.push_back( b1 );
            buf.push_back( b2 );
            buf.push_back( b3 );
            buf.push_back( b4 );
            buf.push_back( b5 );
        }

        template<typename T>
        inline string toString( T doubleval, int precisionval )
        {
            std::string trimmedstring = std::to_string( doubleval ).substr( 0, std::to_string( doubleval ).find( "." ) + precisionval + 1 );
            return trimmedstring;
        }

        inline void NorthOffsetAdd( float X, float Y,float &Z )
        {
            double v1 = static_cast<double>( X ) + static_cast<double>( Y );
            if ( v1 > 360.0 || v1 < 0.0 )
            {
                double v2 = floor( v1 / 360.0 );
                v1 = v1 - ( v2 * 360.0 );
            }
            Z = v1;
        }

        inline string Replace( std::string str,  std::string from,  std::string to ) {
            string ret       = str;
            size_t start_pos = ret.find( from );
            if( start_pos == std::string::npos )
                return ret;
            ret.replace( start_pos, from.length(), to );
            return ret;
        }

        template<typename T, int N>
        inline T fromBuf_LittleEndian( const std::array<uint8_t, ZafarDefines::Consts::RxBufSize>& buf,
                                       int                                                         start )
        {
            T ret = 0;
            for( int i = 0; i < N; ++i )
            {
                int idx = ( start + i ) % ZafarDefines::Consts::RxBufSize;
                ret *= 256;
                ret += buf[idx];
            }

            return ret;
        }

        template<typename T, int N>
        inline T fromBuf_BigEndian( const std::array<uint8_t, ZafarDefines::Consts::RxBufSize>& buf,
                                    int                                                         start )
        {
            T ret = 0;
            for( int i = 0; i < N; ++i )
            {
                int idx = ( start + i ) % ZafarDefines::Consts::RxBufSize;
                ret += ( buf[idx] * pow( 256, i ) );
            }

            return ret;
        }

        template<typename T, int N>
        inline void toBuf_LittleEndian( std::vector<uint8_t>& buf,
                                        T                     val )
        {
            for( int i = 0; i < N; ++i )
            {
                buf.push_back( static_cast<uint8_t>( val / pow(256, i) ) );
            }
        }

        template<typename T, int N>
        inline void toBuf_BigEndian( std::vector<uint8_t>& buf,
                                       T                     val )
        {
            for( int i = 0; i < N; ++i )
            {
                buf.push_back( static_cast<uint8_t>( val / pow(256, N - i - 1) ) );
            }
        }

        template<typename T, int N>
        inline T fromBitSet( const std::bitset<N>& bits,
                             int                   start,
                             int                   stop )
        {
            T ret = 0;
            for( int i = start; i < stop; ++i )
            {
                ret += ( bits[i] * pow( 2, i ) );
            }

            return ret;
        }

    }

    namespace Classes
    {
        class __attribute__( ( packed ) ) Bitwise_1_1_1_1_1_1_1_1
        {
            public:
                uint8_t b0 : 1;
                uint8_t b1 : 1;
                uint8_t b2 : 1;
                uint8_t b3 : 1;
                uint8_t b4 : 1;
                uint8_t b5 : 1;
                uint8_t b6 : 1;
                uint8_t b7 : 1;

                template<typename T>
                Bitwise_1_1_1_1_1_1_1_1( T val = 0 )
                {
                    set( val );
                }

                void  clear()
                {
                    memset( (char *)this, 0, 1 );
                }

                template<typename T>
                void  set( T buf )
                {
                    memcpy( (char *)this, &buf, 1 );
                }

                template<typename T>
                T  value()
                {
                    T ret;

                    memcpy( (char *)&ret, (char *)this, 1 );

                    return ret;
                }
        };

        class __attribute__( ( packed ) ) Bitwise_1_6_1
        {
            public:
                uint8_t b0 : 1;
                uint8_t b1 : 6;
                uint8_t b2 : 1;

                template<typename T>
                Bitwise_1_6_1( T val = 0 )
                {
                    set( val );
                }

                void  clear()
                {
                    memset( (char *)this, 0, 1 );
                }

                template<typename T>
                void  set( T buf )
                {
                    memcpy( (char *)this, &buf, 1 );
                }

                template<typename T>
                T  value()
                {
                    T ret;

                    memcpy( (char *)&ret, (char *)this, 1 );

                    return ret;
                }
        };

        class __attribute__( ( packed ) ) Bitwise_4_4
        {
            public:
                uint8_t b0 : 4;
                uint8_t b1 : 4;

                template<typename T>
                Bitwise_4_4( T val = 0 )
                {
                    set( val );
                }

                void  clear()
                {
                    memset( (char *)this, 0, 1 );
                }

                template<typename T>
                void  set( T buf )
                {
                    memcpy( (char *)this, &buf, 1 );
                }

                template<typename T>
                T  value()
                {
                    T ret;

                    memcpy( (char *)&ret, (char *)this, 1 );

                    return ret;
                }
        };

        class __attribute__( ( packed ) ) Bitwise_5_3
        {
            public:
                uint8_t b0 : 3;
                uint8_t b1 : 5;

                template<typename T>
                Bitwise_5_3( T val = 0 )
                {
                    set( val );
                }

                void  clear()
                {
                    memset( (char *)this, 0, 1 );
                }

                template<typename T>
                void  set( T buf )
                {
                    memcpy( (char *)this, &buf, 1 );
                }

                template<typename T>
                T  value()
                {
                    T ret;

                    memcpy( (char *)&ret, (char *)this, 1 );

                    return ret;
                }
        };

        class RequestTokenHolder
        {
            public:
                static int Token()
                {
                    if( _token == 0 )
                    {
                        srand( time( 0 ) );
                        _token = rand() + 1;
                    }
                    return _token;
                }

            private:
                RequestTokenHolder() {
                }

                static int _token;
        };

        class Timer
        {
            public:
                void start()
                {
                    m_StartTime = std::chrono::system_clock::now();
                    m_bRunning  = true;
                }

                void stop()
                {
                    m_EndTime  = std::chrono::system_clock::now();
                    m_bRunning = false;
                }

                void restart()
                {
                    stop();
                    start();
                }

                uint64_t elapsedMilliseconds()
                {
                    std::chrono::time_point<std::chrono::system_clock> endTime;

                    if( m_bRunning )
                    {
                        endTime = std::chrono::system_clock::now();
                    }
                    else
                    {
                        endTime = m_EndTime;
                    }

                    return std::chrono::duration_cast<std::chrono::milliseconds>( endTime - m_StartTime ).count();
                }

                uint64_t elapsedNanoseconds()
                {
                    std::chrono::time_point<std::chrono::system_clock> endTime;

                    if( m_bRunning )
                    {
                        endTime = std::chrono::system_clock::now();
                    }
                    else
                    {
                        endTime = m_EndTime;
                    }

                    return std::chrono::duration_cast<std::chrono::nanoseconds>( endTime - m_StartTime ).count();
                }

                double elapsedSeconds()
                {
                    return elapsedMilliseconds() / 1000.0;
                }

            private:
                std::chrono::time_point<std::chrono::system_clock> m_StartTime;
                std::chrono::time_point<std::chrono::system_clock> m_EndTime;
                bool                                               m_bRunning = false;
        };

        struct BlockBinsData
        {
            uint8_t         ActiveBlockBin : 1;
            uint8_t         SubBandNum     : 7;
            uint32_t        ActiveBin1     : 1;
            uint32_t        StartBin1      : 6;
            uint32_t        StopBin1       : 6;
            uint32_t        ModeBin1       : 3;
            uint32_t        ActiveBin2     : 1;
            uint32_t        StartBin2      : 6;
            uint32_t        StopBin2       : 6;
            uint32_t        ModeBin2       : 3;
            uint16_t        ActiveBin3     : 1;
            uint16_t        StartBin3      : 6;
            uint16_t        StopBin3       : 6;
            uint16_t        ModeBin3       : 3;
            uint8_t         res            : 8;
        } __attribute__( ( packed ) );
    }
}
