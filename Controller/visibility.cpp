#pragma once

namespace uk { 

    express_tcp_t visibility() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send();

            for( auto& size: map_t<string_t,int>({ 
                { "\\@s",  640 },
                { "\\@m",  960 },
                { "\\@l", 1200 },
                { "\\@2l",1600 }
            }).data() ){

                if( size.first != nullptr ){
                    cli.write( regex::format( _STRING_(
                       @media( min-width: ${0}px ) {
                    ), size.second ));
                }

                cli.write( regex::format( _STRING_(
                   .uk-visible${0} { display: none !important; }
                ), size.first ));

                if( size.first != nullptr ){ cli.write( "}" ); }

            }

            for( auto& size: map_t<string_t,int>({ 
                { nullptr,   0 },
                { "\\@s",  640 },
                { "\\@m",  960 },
                { "\\@l", 1200 },
                { "\\@2l",1600 }
            }).data() ){

                if( size.first != nullptr ){
                    cli.write( regex::format( _STRING_(
                       @media( min-width: ${0}px ) {
                    ), size.second ));
                }

                cli.write( regex::format( _STRING_(
                   .uk-hidden${0} { display: none !important; }
                ), size.first ));

                if( size.first != nullptr ){ cli.write( "}" ); }

            }

        });

        return app;
    }

}